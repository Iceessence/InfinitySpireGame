#pragma once
#include "CoreMinimal.h"
#include "VoxelBlock.generated.h"

UENUM(BlueprintType)
enum class EBlockType : uint8
{
    Air         UMETA(DisplayName="Air"),
    Dirt        UMETA(DisplayName="Dirt"),
    Stone       UMETA(DisplayName="Stone"),
    Wood        UMETA(DisplayName="Wood"),
    Workbench   UMETA(DisplayName="Workbench"),
    Furnace     UMETA(DisplayName="Furnace"),
};

USTRUCT(BlueprintType)
struct FBlock
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    EBlockType BlockType = EBlockType::Air;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    uint8 Meta = 0; // optional subtype/rotation/etc.
};
