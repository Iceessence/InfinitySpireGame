#include "SurvivalComponent.h"

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
    if (GetOwnerRole() == ROLE_Authority)
    {
        Health = FMath::Clamp(Health - Amount, 0, 100);
    }
}

void USurvivalComponent::EatFood(int32 Nutrition)
{
    if (GetOwnerRole() == ROLE_Authority)
    {
        Hunger = FMath::Clamp(Hunger - Nutrition, 0, 100);
    }
}

void USurvivalComponent::ConsumeStamina(int32 Amount)
{
    if (GetOwnerRole() == ROLE_Authority)
    {
        Stamina = FMath::Clamp(Stamina - Amount, 0, 100);
    }
}
