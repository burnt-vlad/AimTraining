// Aim Training Game. Fedosov Vladislav

#include "AccuracyHUD.h"
#include "AimTrainingProject/GameModes/AccuracyGameMode.h"

void AAccuracyHUD::BeginPlay()
{
	Super::BeginPlay();

	if (GetWorld())
	{
		const auto GameMode = Cast<AAccuracyGameMode>(GetWorld()->GetAuthGameMode());
		if (GameMode)
		{
			GameMode->OnMatchStateChanged.AddUObject(this, &AAccuracyHUD::OnMatchStateChanged);
		}
	}
}