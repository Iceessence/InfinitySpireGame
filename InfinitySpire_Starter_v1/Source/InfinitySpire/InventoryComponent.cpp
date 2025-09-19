#include "InventoryComponent.h"
#include "Net/UnrealNetwork.h"

UInventoryComponent::UInventoryComponent()
{
    PrimaryComponentTick.bCanEverTick = false;
    SetIsReplicatedByDefault(true);
}

void UInventoryComponent::BeginPlay()
{
    Super::BeginPlay();
    EnsureCapacity();
}

void UInventoryComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    DOREPLIFETIME(UInventoryComponent, Slots);
}

void UInventoryComponent::EnsureCapacity()
{
    if (Slots.Num() < NumSlots)
    {
        Slots.SetNum(NumSlots);
    }
}

int32 UInventoryComponent::FindFirstStack(EBlockType Type) const
{
    for (int32 i = 0; i < Slots.Num(); ++i)
    {
        if (Slots[i].ItemType == Type && Slots[i].Quantity < Slots[i].MaxStack)
        {
            return i;
        }
    }
    return INDEX_NONE;
}

int32 UInventoryComponent::FindFirstEmpty() const
{
    for (int32 i = 0; i < Slots.Num(); ++i)
    {
        if (Slots[i].ItemType == EBlockType::Air || Slots[i].Quantity <= 0)
        {
            return i;
        }
    }
    return INDEX_NONE;
}

int32 UInventoryComponent::AddItem(EBlockType ItemType, int32 Amount)
{
    EnsureCapacity();
    int32 Remaining = Amount;

    // Try stack into existing
    while (Remaining > 0)
    {
        int32 stackIdx = FindFirstStack(ItemType);
        if (stackIdx == INDEX_NONE) break;
        int32 canAdd = Slots[stackIdx].MaxStack - Slots[stackIdx].Quantity;
        int32 addNow = FMath::Min(canAdd, Remaining);
        Slots[stackIdx].ItemType = ItemType;
        Slots[stackIdx].Quantity += addNow;
        Remaining -= addNow;
    }

    // Place into empties
    while (Remaining > 0)
    {
        int32 emptyIdx = FindFirstEmpty();
        if (emptyIdx == INDEX_NONE) break;
        int32 addNow = FMath::Min(Slots[emptyIdx].MaxStack, Remaining);
        Slots[emptyIdx].ItemType = ItemType;
        Slots[emptyIdx].Quantity = addNow;
        Remaining -= addNow;
    }

    return Amount - Remaining;
}

int32 UInventoryComponent::RemoveItem(EBlockType ItemType, int32 Amount)
{
    int32 Remaining = Amount;

    for (int32 i = 0; i < Slots.Num() && Remaining > 0; ++i)
    {
        if (Slots[i].ItemType == ItemType && Slots[i].Quantity > 0)
        {
            int32 take = FMath::Min(Slots[i].Quantity, Remaining);
            Slots[i].Quantity -= take;
            Remaining -= take;
            if (Slots[i].Quantity <= 0)
            {
                Slots[i].ItemType = EBlockType::Air;
            }
        }
    }
    return Amount - Remaining;
}
