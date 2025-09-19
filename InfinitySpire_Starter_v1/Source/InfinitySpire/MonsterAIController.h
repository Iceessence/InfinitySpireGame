#pragma once
#include "CoreMinimal.h"
#include "AIController.h"
#include "MonsterAIController.generated.h"

UCLASS()
class INFINITYSPIRE_API AMonsterAIController : public AAIController
{
    GENERATED_BODY()

public:
    AMonsterAIController();

protected:
    virtual void OnPossess(APawn* InPawn) override;

public:
    UFUNCTION(BlueprintCallable, Category="AI")
    void SetTargetActor(AActor* Target);

private:
    UPROPERTY()
    AActor* CurrentTarget = nullptr;
};
