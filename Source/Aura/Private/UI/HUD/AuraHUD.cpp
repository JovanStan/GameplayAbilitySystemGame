

#include "UI/HUD/AuraHUD.h"

#include "Blueprint/UserWidget.h"
#include "UI/Widgets/AuraUserWidget.h"

void AAuraHUD::BeginPlay()
{
	Super::BeginPlay();

	if (OverlayWidgetClass)
	{
		OverlayWidget = Cast<UAuraUserWidget>(CreateWidget<UUserWidget>(GetWorld(), OverlayWidgetClass));
		OverlayWidget->AddToViewport();
	}
	
}
