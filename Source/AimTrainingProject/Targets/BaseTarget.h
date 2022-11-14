// Aim Training Game. Fedosov Vladislav

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseTarget.generated.h"

UENUM(BlueprintType)
enum class EMovementType : uint8
{
    Static,
    Moving
};

USTRUCT(BlueprintType)
struct FMovementParams
{
    GENERATED_USTRUCT_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Movement")
        float TargetRotateSpeed = 30.f;
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Movement")
        float Amplitude = 60.f;
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Movement")
        float Frequancy = 2.5f;
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Movement")
        EMovementType MovementType = EMovementType::Static;
};

UCLASS()
class AIMTRAININGPROJECT_API ABaseTarget : public AActor
{
    GENERATED_BODY()

public:
    ABaseTarget();
    virtual void Tick(float DeltaTime) override;
    void ActivateTarget();
    void DeactivateTarget();
    bool GetCondition() { return IsAvailable; };

protected:
    virtual void BeginPlay() override;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Components")
        USceneComponent* SceneComponent;
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Components")
        UStaticMeshComponent* TargetMesh;
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Movement")
        FMovementParams MovementParams;

private:

    bool IsAvailable;
    void TurnTargetUp(float DeltaTime);
    void TurnTargetDown(float DeltaTime);
    void MoveTarget();

    FRotator TargetRotation;
    FRotator InitialTargetRotation;
    FVector InitialTargetLocation;

};
