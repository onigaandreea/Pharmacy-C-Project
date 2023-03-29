#include "lab14.h"
#include "service.h"
#include "medgui.h"
#include "teste.h"
#include "medGuiModel.h"
#include <QtWidgets/QApplication>

void adaugaCateva(Pharmacy& srv) {
	srv.addMed("a", "aa", "a", 6);
	srv.addMed("z", "bb", "ab", 30);
	srv.addMed("d", "bc", "b", 10);
	srv.addMed("g", "bb", "a", 20);
	srv.addMed("c", "aa", "ab", 22);
	srv.addMed("b", "ab", "a", 32);
	srv.addMed("e", "bb", "bc", 15);
}

int runGUI(int argc, char* argv[])
{
	QApplication a(argc, argv);
	MedRepo rep;
	MedValidator val;
	Pharmacy ctr{ rep, val };
	Reteta reteta{ rep };
	adaugaCateva(ctr);
	//PharmacyGUI gui{ ctr };
	PharmacyGUIModel gui{ ctr };
	gui.show();
	return a.exec();
}

int main(int argc, char* argv[])
{
	testValidator();
	testeDomeniu();
	testeRepo();
	testeSrv();
	testfiltrare();
	testsortare();
	testUndo();
	testdict();
	testRetetaSrv();

	runGUI(argc, argv);

	return 0;
}

