#include "PlayerCharacter.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/SpringArmComponent.h"

APlayerCharacter::APlayerCharacter()
{
    PrimaryActorTick.bCanEverTick = true;
    bReplicates = true;

    Inventory = CreateDefaultSubobject<UInventoryComponent>(TEXT("Inventory"));
    Survival  = CreateDefaultSubobject<USurvivalComponent>(TEXT("Survival"));

    // First-person camera
    FirstPersonCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FirstPersonCamera"));
    FirstPersonCamera->SetupAttachment(GetCapsuleComponent());
    FirstPersonCamera->SetRelativeLocation(FirstPersonCameraOffset);
    FirstPersonCamera->bUsePawnControlRotation = true;

    // Third-person camera
    ThirdPersonSpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("ThirdPersonSpringArm"));
    ThirdPersonSpringArm->SetupAttachment(GetCapsuleComponent());
    ThirdPersonSpringArm->TargetArmLength = ThirdPersonArmLength;
    ThirdPersonSpringArm->bUsePawnControlRotation = true;
    ThirdPersonSpringArm->SetRelativeLocation(FVector(0.f, 0.f, 60.f));

    ThirdPersonCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("ThirdPersonCamera"));
    ThirdPersonCamera->SetupAttachment(ThirdPersonSpringArm, USpringArmComponent::SocketName);
    ThirdPersonCamera->bUsePawnControlRotation = false;

    if (UCharacterMovementComponent* MoveComp = GetCharacterMovement())
    {
        MoveComp->bOrientRotationToMovement = false;
    }

    bUseControllerRotationYaw = true;
}

void APlayerCharacter::BeginPlay()
{
    Super::BeginPlay();
    UpdateViewMode();
}

void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);
    check(PlayerInputComponent);

    PlayerInputComponent->BindAxis("MoveForward", this, &APlayerCharacter::MoveForward);
    PlayerInputComponent->BindAxis("MoveRight", this, &APlayerCharacter::MoveRight);
    PlayerInputComponent->BindAxis("Turn", this, &APlayerCharacter::Turn);
    PlayerInputComponent->BindAxis("LookUp", this, &APlayerCharacter::LookUp);

    PlayerInputComponent->BindAction("ToggleView", IE_Pressed, this, &APlayerCharacter::ToggleCamera);
}

void APlayerCharacter::MoveForward(float Value)
{
    if (Controller && Value != 0.0f)
    {
        const FRotator YawRot(0.f, Controller->GetControlRotation().Yaw, 0.f);
        const FVector Direction = FRotationMatrix(YawRot).GetUnitAxis(EAxis::X);
        AddMovementInput(Direction, Value);
    }
}

void APlayerCharacter::MoveRight(float Value)
{
    if (Controller && Value != 0.0f)
    {
        const FRotator YawRot(0.f, Controller->GetControlRotation().Yaw, 0.f);
        const FVector Direction = FRotationMatrix(YawRot).GetUnitAxis(EAxis::Y);
        AddMovementInput(Direction, Value);
    }
}

void APlayerCharacter::Turn(float Value)
{
    AddControllerYawInput(Value);
}

void APlayerCharacter::LookUp(float Value)
{
    AddControllerPitchInput(Value);
}

void APlayerCharacter::ToggleCamera()
{
    bFirstPerson = !bFirstPerson;
    UpdateViewMode();
}

void APlayerCharacter::UpdateViewMode()
{
    if (FirstPersonCamera && ThirdPersonCamera)
    {
        FirstPersonCamera->SetActive(bFirstPerson);
        ThirdPersonCamera->SetActive(!bFirstPerson);
        FirstPersonCamera->SetRelativeLocation(FirstPersonCameraOffset);
    }

    if (ThirdPersonSpringArm)
    {
        ThirdPersonSpringArm->TargetArmLength = ThirdPersonArmLength;
        ThirdPersonSpringArm->bUsePawnControlRotation = !bFirstPerson;
    }

    bUseControllerRotationYaw = bFirstPerson;

    if (UCharacterMovementComponent* MoveComp = GetCharacterMovement())
    {
        MoveComp->bOrientRotationToMovement = !bFirstPerson;
    }
}
