#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "VoxelWorld.generated.h"

/**
 * Placeholder Actor for voxel chunk generation and meshing.
 * Replace with ProceduralMeshComponent or RuntimeMeshComponent usage.
 */
UCLASS()
class INFINITYSPIRE_API AVoxelWorld : public AActor
{
    GENERATED_BODY()

public:
    AVoxelWorld();

protected:
    virtual void BeginPlay() override;

public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Voxels")
    int32 Seed = 1337;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Voxels")
    int32 ChunkSize = 16;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Voxels")
    int32 WorldRadiusInChunks = 4;

    UFUNCTION(BlueprintCallable, Category="Voxels")
    void GenerateTestGround();
};
