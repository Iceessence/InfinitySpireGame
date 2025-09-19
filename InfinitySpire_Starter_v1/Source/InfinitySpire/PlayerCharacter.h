#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InventoryComponent.h"
#include "SurvivalComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "PlayerCharacter.generated.h"

UCLASS()
class INFINITYSPIRE_API APlayerCharacter : public ACharacter
{
    GENERATED_BODY()

public:
    APlayerCharacter();

protected:
    virtual void BeginPlay() override;
    virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components")
    UInventoryComponent* Inventory;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components")
    USurvivalComponent* Survival;

    // Cameras
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Camera")
    UCameraComponent* FirstPersonCamera;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Camera")
    USpringArmComponent* ThirdPersonSpringArm;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Camera")
    UCameraComponent* ThirdPersonCamera;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Camera")
    bool bFirstPerson = true;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Camera")
    FVector FirstPersonCameraOffset = FVector(-10.f, 0.f, 60.f);

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Camera")
    float ThirdPersonArmLength = 350.f;

    UFUNCTION(BlueprintCallable, Category="Camera")
    void ToggleCamera();

private:
    void MoveForward(float Value);
    void MoveRight(float Value);
    void Turn(float Value);
    void LookUp(float Value);
    void UpdateViewMode();
};
