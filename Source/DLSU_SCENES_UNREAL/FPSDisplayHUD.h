#include "FPSDisplayHUD.h"
#include "Engine/Canvas.h"
#include "Engine/Engine.h"

void AFPSDisplayHUD::DrawHUD()
{
    Super::DrawHUD();

    float DeltaSeconds = GetWorld()->GetDeltaSeconds();
    float CurrentFPS = 1.0f / FMath::Max(DeltaSeconds, KINDA_SMALL_NUMBER);

    // Add to history
    FPSHistory.Add(CurrentFPS);
    if (FPSHistory.Num() > MaxHistorySize)
    {
        FPSHistory.RemoveAt(0);
    }

    float AvgFPS = CalculateAverageFPS();

    DrawAverageFPS(AvgFPS);
    DrawFPSGraph();
}

float AFPSDisplayHUD::CalculateAverageFPS() const
{
    if (FPSHistory.Num() == 0) return 0.f;

    float Sum = 0.f;
    for (float FPS : FPSHistory)
    {
        Sum += FPS;
    }
    return Sum / FPSHistory.Num();
}

void AFPSDisplayHUD::DrawAverageFPS(float AvgFPS)
{
    FString FPSString = FString::Printf(TEXT("Average FPS: %.1f"), AvgFPS);
    FCanvasTextItem TextItem(FVector2D(50, 50), FText::FromString(FPSString), GEngine->GetSmallFont(), FLinearColor::White);
    Canvas->DrawItem(TextItem);
}

void AFPSDisplayHUD::DrawFPSGraph()
{
    float BarWidth = 3.0f;
    float GraphHeight = 100.0f;
    float BaseX = 50.0f;
    float BaseY = 100.0f;

    for (int32 i = 0; i < FPSHistory.Num(); ++i)
    {
        float FPS = FPSHistory[i];
        float HeightRatio = FMath::Clamp(FPS / MaxExpectedFPS, 0.0f, 1.0f);
        float BarHeight = HeightRatio * GraphHeight;

        FLinearColor BarColor;
        if (FPS > 60)
            BarColor = FLinearColor::Green;
        else if (FPS > 30)
            BarColor = FLinearColor::Yellow;
        else
            BarColor = FLinearColor::Red;

        FVector2D BarPos(BaseX + i * BarWidth, BaseY + (GraphHeight - BarHeight));
        FVector2D BarSize(BarWidth - 1.0f, BarHeight);

        FCanvasTileItem Tile(BarPos, BarSize, BarColor);
        Tile.BlendMode = SE_BLEND_Translucent;
        Canvas->DrawItem(Tile);
    }