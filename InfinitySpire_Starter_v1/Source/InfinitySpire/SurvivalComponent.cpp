#include "SurvivalComponent.h"
#include "GameFramework/Actor.h"
#include "Net/UnrealNetwork.h"

USurvivalComponent::USurvivalComponent()
{
    PrimaryComponentTick.bCanEverTick = false;
    SetIsReplicatedByDefault(true);
}

void USurvivalComponent::BeginPlay()
{
    Super::BeginPlay();
}

void USurvivalComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    DOREPLIFETIME(USurvivalComponent, Health);
    DOREPLIFETIME(USurvivalComponent, Hunger);
    DOREPLIFETIME(USurvivalComponent, Stamina);
}

void USurvivalComponent::ApplyDamage(int32 Amount)
{
    if (const AActor* Owner = GetOwner())
    {
        if (Owner->HasAuthority())
        {
            Health = FMath::Clamp(Health - Amount, 0, 100);
        }
    }
}

void USurvivalComponent::EatFood(int32 Nutrition)
{
    if (const AActor* Owner = GetOwner())
    {
        if (Owner->HasAuthority())
        {
            Hunger = FMath::Clamp(Hunger - Nutrition, 0, 100);
        }
    }
}

void USurvivalComponent::ConsumeStamina(int32 Amount)
{
    if (const AActor* Owner = GetOwner())
    {
        if (Owner->HasAuthority())
        {
            Stamina = FMath::Clamp(Stamina - Amount, 0, 100);
        }
    }
}
