#include "MonsterAIController.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Character.h"

AMonsterAIController::AMonsterAIController()
{
    bAttachToPawn = true;
}

void AMonsterAIController::OnPossess(APawn* InPawn)
{
    Super::OnPossess(InPawn);
    // Placeholder: pick first player as target
    TArray<AActor*> Players;
    UGameplayStatics::GetAllActorsOfClass(GetWorld(), ACharacter::StaticClass(), Players);
    if (Players.Num() > 0)
    {
        CurrentTarget = Players[0];
        MoveToActor(CurrentTarget, 150.f, true, true, true, 0, true);
    }
}

void AMonsterAIController::SetTargetActor(AActor* Target)
{
    CurrentTarget = Target;
    if (CurrentTarget)
    {
        MoveToActor(CurrentTarget, 150.f, true, true, true, 0, true);
    }
}
