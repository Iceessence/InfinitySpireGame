#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "VoxelWorld.generated.h"

class UInstancedStaticMeshComponent;
class USceneComponent;

/**
 * Minimal voxel world actor that spawns an instanced static-mesh ground grid
 * so the project boots into a playable level without additional setup.
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
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Voxels", meta=(AllowPrivateAccess="true"))
    USceneComponent* SceneRoot;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Voxels", meta=(AllowPrivateAccess="true"))
    UInstancedStaticMeshComponent* GroundMesh;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Voxels")
    int32 Seed = 1337;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Voxels", meta=(ClampMin="4", ClampMax="64"))
    int32 ChunkSize = 16;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Voxels", meta=(ClampMin="1", ClampMax="12"))
    int32 WorldRadiusInChunks = 4;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Voxels", meta=(ClampMin="10.0", ClampMax="500.0"))
    float BlockSize = 100.f;

    UFUNCTION(BlueprintCallable, Category="Voxels")
    void GenerateTestGround();
};
