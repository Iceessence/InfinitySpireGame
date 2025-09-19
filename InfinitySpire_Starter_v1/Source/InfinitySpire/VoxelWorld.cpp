#include "VoxelWorld.h"
#include "Components/InstancedStaticMeshComponent.h"
#include "Components/SceneComponent.h"
#include "Engine/CollisionProfile.h"
#include "Engine/StaticMesh.h"
#include "Engine/World.h"
#include "GameFramework/Actor.h"
#include "UObject/ConstructorHelpers.h"

AVoxelWorld::AVoxelWorld()
{
    PrimaryActorTick.bCanEverTick = false;
    bReplicates = true;
    SetReplicatingMovement(false);

    SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
    RootComponent = SceneRoot;

    GroundMesh = CreateDefaultSubobject<UInstancedStaticMeshComponent>(TEXT("GroundMesh"));
    GroundMesh->SetupAttachment(SceneRoot);
    GroundMesh->SetCollisionProfileName(UCollisionProfile::BlockAll_ProfileName);
    GroundMesh->SetMobility(EComponentMobility::Static);
    GroundMesh->SetCanEverAffectNavigation(false);

    static ConstructorHelpers::FObjectFinder<UStaticMesh> CubeMesh(TEXT("/Engine/BasicShapes/Cube.Cube"));
    if (CubeMesh.Succeeded())
    {
        GroundMesh->SetStaticMesh(CubeMesh.Object);
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("VoxelWorld could not find /Engine/BasicShapes/Cube mesh."));
    }
}

void AVoxelWorld::BeginPlay()
{
    Super::BeginPlay();
    GenerateTestGround();
}

void AVoxelWorld::GenerateTestGround()
{
    if (!GroundMesh || !GroundMesh->GetStaticMesh())
    {
        return;
    }

    GroundMesh->ClearInstances();

    const int32 ExtentInBlocks = FMath::Clamp(WorldRadiusInChunks * ChunkSize, 1, 512);
    const float HalfBlock = BlockSize * 0.5f;

    FRandomStream Random(Seed);

    for (int32 X = -ExtentInBlocks; X <= ExtentInBlocks; ++X)
    {
        for (int32 Y = -ExtentInBlocks; Y <= ExtentInBlocks; ++Y)
        {
            const float Noise = Random.FRandRange(-4.f, 4.f);
            const FVector Location(X * BlockSize, Y * BlockSize, -HalfBlock + Noise);
            const FTransform InstanceTransform(FRotator::ZeroRotator, Location, FVector(1.f, 1.f, 1.f));
            GroundMesh->AddInstance(InstanceTransform);
        }
    }
}
