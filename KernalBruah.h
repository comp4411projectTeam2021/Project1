#pragma once

#include "ImpBrush.h"
#include <string>
#include <vector>;


class KernalBruah :ImpBrush {
public:	
		KernalBruah(ImpressionistDoc* pDoc = NULL);
		
		virtual void BrushBegin(const Point source, const Point target) override;

		virtual void BrushMove(const Point source, const Point target) override;

		virtual void BrushEnd(const Point source, const Point target) override;

		static KernalBruah* GenerateConverlution(ImpressionistDoc* pDoc, char* weights, bool normalize = true);
private:
	int size;
	float sum;
	std::vector<float> kernal;
};