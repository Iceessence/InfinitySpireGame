#include "InfinitySpireGameMode.h"
#include "PlayerCharacter.h"
#include "VoxelWorld.h"
#include "Engine/World.h"
#include "EngineUtils.h"

AInfinitySpireGameMode::AInfinitySpireGameMode()
{
    DefaultPawnClass = APlayerCharacter::StaticClass();
}

void AInfinitySpireGameMode::BeginPlay()
{
    Super::BeginPlay();

    if (UWorld* World = GetWorld())
    {
        bool bHasVoxelWorld = false;
        for (TActorIterator<AVoxelWorld> It(World); It; ++It)
        {
            bHasVoxelWorld = true;
            break;
        }

        if (!bHasVoxelWorld)
        {
            FActorSpawnParameters Params;
            Params.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;
            World->SpawnActor<AVoxelWorld>(FVector::ZeroVector, FRotator::ZeroRotator, Params);
        }
    }
}
