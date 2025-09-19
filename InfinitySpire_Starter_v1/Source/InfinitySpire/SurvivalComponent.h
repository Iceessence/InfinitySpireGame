#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Net/UnrealNetwork.h"
#include "SurvivalComponent.generated.h"

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class INFINITYSPIRE_API USurvivalComponent : public UActorComponent
{
    GENERATED_BODY()

public:
    USurvivalComponent();

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Replicated, Category="Survival")
    int32 Health = 100;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Replicated, Category="Survival")
    int32 Hunger = 0; // 0=full, 100=starving

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Replicated, Category="Survival")
    int32 Stamina = 100;

protected:
    virtual void BeginPlay() override;
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

public:
    UFUNCTION(BlueprintCallable, Category="Survival")
    void ApplyDamage(int32 Amount);

    UFUNCTION(BlueprintCallable, Category="Survival")
    void EatFood(int32 Nutrition);

    UFUNCTION(BlueprintCallable, Category="Survival")
    void ConsumeStamina(int32 Amount);
};
