// Aim Training Game. Fedosov Vladislav


#include "AccuracyTimerWidget.h"
#include "AimTrainingProject/GameModes/AccuracyGameMode.h"

int32 UAccuracyTimerWidget::GetTimeRemaining() const
{
	const auto AccuracyGameMode = GetAccuracyGameMode();
	return AccuracyGameMode ? AccuracyGameMode->GetRoundCountDown() : 0;
}

AAccuracyGameMode* UAccuracyTimerWidget::GetAccuracyGameMode() const
{
	return GetWorld() ? Cast<AAccuracyGameMode>(GetWorld()->GetAuthGameMode()) : nullptr;
}