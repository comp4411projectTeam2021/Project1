#include "impressionistDoc.h"
#include "impressionistUI.h"
#include "linebrush.h"
#include <iostream>
extern float frand();

LineBrush::LineBrush(ImpressionistDoc* pDoc, char* name) :
	ImpBrush(pDoc, name)
{
}

void LineBrush::BrushBegin(const Point source, const Point target)
{
	
	ImpressionistDoc* pDoc = GetDocument();
	ImpressionistUI* dlg = pDoc->m_pUI;
	//if (!(target.x >= 0 && target.x < pDoc->m_nWidth && target.y >= 0 && target.y < pDoc->m_nHeight))return;
	//std::cout << target.x << "   " << target.y << std::endl;
	int size = pDoc->getSize();

	glBegin(GL_LINES);
	SetColor(source);
	glVertex2d(target.x - size / 2, target.y);
	glVertex2d(target.x + size / 2, target.y);
	glEnd();

	//glPointSize((float)size);

	//BrushMove(source, target);
}

void LineBrush::BrushMove(const Point source, const Point target)
{/*
	ImpressionistDoc* pDoc = GetDocument();
	ImpressionistUI* dlg = pDoc->m_pUI;

	if (pDoc == NULL) {
		printf("LineBrush::BrushMove  document is NULL\n");
		return;
	}

	glBegin(GL_LINES);
	SetColor(source);

	glVertex2d(target.x, target.y);

	glEnd();*/
	BrushBegin(source, target);
}

void LineBrush::BrushEnd(const Point source, const Point target){}

