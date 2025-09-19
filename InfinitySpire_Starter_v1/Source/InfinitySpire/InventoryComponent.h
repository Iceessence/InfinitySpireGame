#pragma once
#include "CoreMinimal.h"
#include "VoxelBlock.h"
#include "Components/ActorComponent.h"
#include "Net/UnrealNetwork.h"
#include "InventoryComponent.generated.h"

USTRUCT(BlueprintType)
struct FInventorySlot
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    EBlockType ItemType = EBlockType::Air;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 Quantity = 0;

    // Optional max stack size (data-only, not enforced here)
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 MaxStack = 99;
};

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class INFINITYSPIRE_API UInventoryComponent : public UActorComponent
{
    GENERATED_BODY()

public:
    UInventoryComponent();

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, Category="Inventory")
    TArray<FInventorySlot> Slots;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Inventory")
    int32 NumSlots = 20;

    // Adds up to Amount; returns actually added
    UFUNCTION(BlueprintCallable, Category="Inventory")
    int32 AddItem(EBlockType ItemType, int32 Amount);

    // Removes up to Amount; returns actually removed
    UFUNCTION(BlueprintCallable, Category="Inventory")
    int32 RemoveItem(EBlockType ItemType, int32 Amount);

protected:
    virtual void BeginPlay() override;
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

private:
    int32 FindFirstStack(EBlockType Type) const;
    int32 FindFirstEmpty() const;
    void EnsureCapacity();
};
