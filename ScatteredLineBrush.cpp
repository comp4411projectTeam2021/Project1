#include "impressionistDoc.h"
#include "impressionistUI.h"
#include "ScatteredLineBrush.h"
#include <iostream>
extern float frand();

ScatteredLineBrush::ScatteredLineBrush(ImpressionistDoc* pDoc, char* name) :
	ImpBrush(pDoc, name)
{
}

void ScatteredLineBrush::BrushBegin(const Point source, const Point target)
{

	ImpressionistDoc* pDoc = GetDocument();
	ImpressionistUI* dlg = pDoc->m_pUI;
	//if (!(target.x >= 0 && target.x < pDoc->m_nWidth && target.y >= 0 && target.y < pDoc->m_nHeight))return;
	//std::cout << target.x << "   " << target.y << std::endl;
	int size = pDoc->getSize();

	glBegin(GL_LINES);
	for (int i = 0; i < 4; i++)
	{
		int curX = rand() % size;
		int curY = rand() % (2 * size - 1) % size;
		Point curP(source.x + curX - size / 2, source.y + curY - size / 2);
		SetColor(curP);
		glVertex2d(curP.x - size / 2, curP.y);
		glVertex2d(curP.x + size / 2, curP.y);
	}
	glEnd();

	//glPointSize((float)size);

	//BrushMove(source, target);
}

void ScatteredLineBrush::BrushMove(const Point source, const Point target)
{/*
	ImpressionistDoc* pDoc = GetDocument();
	ImpressionistUI* dlg = pDoc->m_pUI;

	if (pDoc == NULL) {
		printf("ScatteredLineBrush::BrushMove  document is NULL\n");
		return;
	}

	glBegin(GL_LINES);
	SetColor(source);

	glVertex2d(target.x, target.y);

	glEnd();*/
	BrushBegin(source, target);
}

void ScatteredLineBrush::BrushEnd(const Point source, const Point target) {}

