// Aim Training Game. Fedosov Vladislav

#include "AimTrainingProject/Targets/BaseTarget.h"
#include "Kismet/GameplayStatics.h"

DEFINE_LOG_CATEGORY_STATIC(LogTarget, All, All);

ABaseTarget::ABaseTarget()
{
    PrimaryActorTick.bCanEverTick = true;
    SceneComponent = CreateDefaultSubobject<USceneComponent>("SceneComponent");
    SetRootComponent(SceneComponent);
    TargetMesh = CreateDefaultSubobject<UStaticMeshComponent>("TargetMesh");
    TargetMesh->SetupAttachment(SceneComponent);
    SetActorEnableCollision(false);
    IsAvailable = false;
}

void ABaseTarget::BeginPlay()
{
    Super::BeginPlay();
    InitialTargetRotation = TargetMesh->GetRelativeRotation();
    InitialTargetLocation = TargetMesh->GetRelativeLocation();
}


void ABaseTarget::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    TargetRotation = TargetMesh->GetRelativeRotation();
    if (IsAvailable)
    {
        TurnTargetUp(DeltaTime);
        MoveTarget();
    }
    else if (!IsAvailable)
    {
        TurnTargetDown(DeltaTime);
    }

}

void ABaseTarget::TurnTargetUp(float DeltaTime)
{
    TargetMesh->SetRelativeRotation(FMath::Lerp(FQuat(TargetRotation), FQuat(FRotator(InitialTargetRotation.Pitch - 90.f, InitialTargetRotation.Yaw, InitialTargetRotation.Roll)), DeltaTime * MovementParams.TargetRotateSpeed));
}

void ABaseTarget::TurnTargetDown(float DeltaTime)
{
    TargetMesh->SetRelativeRotation(FMath::Lerp(FQuat(TargetRotation), FQuat(InitialTargetRotation), DeltaTime * MovementParams.TargetRotateSpeed));
}

void ABaseTarget::MoveTarget()
{
    switch (MovementParams.MovementType)
    {
    case EMovementType::Static: break;
    case EMovementType::Moving:
    {
        float Time = GetWorld()->GetTimeSeconds();
        FVector CurrentTargetLocation = TargetMesh->GetRelativeLocation();
        CurrentTargetLocation.Y = InitialTargetLocation.Y + MovementParams.Amplitude * FMath::Acos(FMath::Cos(MovementParams.Frequancy * Time));
        TargetMesh->SetRelativeLocation(CurrentTargetLocation);
    }
    default:break;
    }
}

void ABaseTarget::ActivateTarget()
{
    IsAvailable = true;
    SetActorEnableCollision(true);
}

void ABaseTarget::DeactivateTarget()
{
    IsAvailable = false;
    SetActorEnableCollision(false);
}

