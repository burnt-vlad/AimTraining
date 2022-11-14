// Aim Training Game. Fedosov Vladislav


#include "ReactionHUD.h"
#include "AimTrainingProject/GameModes/ReactionGameMode.h"

void AReactionHUD::BeginPlay()
{
	Super::BeginPlay();

	if (GetWorld())
	{
		const auto GameMode = Cast<AReactionGameMode>(GetWorld()->GetAuthGameMode());
		if (GameMode)
		{
			GameMode->OnMatchStateChanged.AddUObject(this, &AReactionHUD::OnMatchStateChanged);
		}
	}
}
