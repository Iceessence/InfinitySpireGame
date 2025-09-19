#include "VoxelWorld.h"
#include "Engine/World.h"
#include "GameFramework/Actor.h"

AVoxelWorld::AVoxelWorld()
{
    PrimaryActorTick.bCanEverTick = false;
    bReplicates = false; // world state will be synchronized via game logic later
}

void AVoxelWorld::BeginPlay()
{
    Super::BeginPlay();
    // Placeholder; call GenerateTestGround() from Blueprint for a simple test or wire real meshing later.
}

void AVoxelWorld::GenerateTestGround()
{
    // Intentionally left as a hook for your meshing/instancing.
    // For a quick visual, you could spawn a few StaticMeshActors in a grid here.
}
