#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "InfinitySpireGameMode.generated.h"

UCLASS()
class INFINITYSPIRE_API AInfinitySpireGameMode : public AGameModeBase
{
    GENERATED_BODY()

public:
    AInfinitySpireGameMode();

protected:
    virtual void BeginPlay() override;
};
