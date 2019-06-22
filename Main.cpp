
//#include "StockImpl.h"
#include "FlowUser.cpp"
//#include "ModelImpl.h"
#include "Model.h"
//#include "ModelHandle.h"
//#include "FlowImpl.h"
#include <vector>
#include <cmath>
#include<iostream>
#include <assert.h> 


void testCase4();
void testCase3();
void testCase2();
void testCase1();
void unitTest();

//PARA RODAR O TEST É PRECISO MUDAR A LINHA 15 ESCOLHENDO QUAL TEST VAI QUERER 
//E MUDAR O DEFINE DO FLOWIMPL PARA O NÚMERO DO TEST QUE ESTÁ TESTANDO

int main()
{
	/*unitTest();
*/	testCase1();
    cout<<"\nExponencial OK"<<endl;
	testCase2();
    cout<<"\nLogistica OK"<<endl;

	testCase3();
	cout<<"\nComplexo OK"<<endl;
	
	/*testCase4();
	cout<<"\nMais Complexo ainda OK"<<endl;
*/	
	return 0;
}




void testCase1() {
//cout<<"ola";
	Model *mod = Model::newModel();
	//ModelHandle *mod = new ModelHandle();
	//ModelHandle *mod2 = new ModelHandle();
	//cout<<"ANTES";
	//*mod = *mod2;
	//cout<<"DEPOIS";
	Model *m1 = mod->newModel();
	Stock &pop1 =  mod->newStock(100, "POP1");
	Stock &pop2 = mod->newStock(0, "POP2");
	Flow &exponencial = mod->createFlow<FlowExponencial>();

	exponencial.setSource(&pop1);
	exponencial.setDestiny(&pop2);
	m1->setFlows(&exponencial);
	m1->setStocks(&pop1);
	m1->setStocks(&pop2);
	m1->execute(0, 100, 0);

	//cout << "VALOR DE POP1:"<< pop1->getValue();
	//cout << pop1->getName();
	//cout << pop3->getName();
	assert(abs(pop1.getValue()-36.6032) < 0.0001);
	assert(abs(pop2.getValue()-63.3968) < 0.0001);
	//delete (ModelHandle*)mod;
}

void testCase2() {
	Model *mod = Model::newModel();
	Model *m1 = mod->newModel();
	Stock &p1 =  mod->newStock(100, "P1");
	Stock &p2 =  mod->newStock(10, "P2");
	Flow &logistica =  mod->createFlow<FlowLogistica>();
	logistica.setSource(&p1);
	logistica.setDestiny(&p2);
	
	m1->setStocks(&p1);
	m1->setStocks(&p2);
	m1->setFlows(&logistica);
	m1->execute(0, 100, 0);
//	cout << "VALOR DE POP1:" << p1->getValue();
	assert(abs(p1.getValue()-88.2167) < 0.0001);
	assert(abs(p2.getValue()-21.7834) < 0.0001);

}


void testCase3() {
	
	Model *mod = Model::newModel();
    Model *m1 = mod->newModel();

	Stock &Q1 = mod->newStock(100, "Q1");
	Stock &Q2 = mod->newStock(0, "Q2");
	Stock &Q3 = mod->newStock(100, "Q3");
	Stock &Q4 = mod->newStock(0, "Q4");
	Stock &Q5 =  mod->newStock(0, "Q5");
	//cout<<"ANTES";
	//Q1 = Q3;
	//cout<<"DEPOIS";
	m1->setStocks(&Q1);
	m1->setStocks(&Q2);
	m1->setStocks(&Q3);
	m1->setStocks(&Q4);
	m1->setStocks(&Q5);
	
	Flow &f = mod->createFlow<FlowExponencial>();
	f.setSource(&Q1);
	f.setDestiny(&Q2);
	m1->setFlows(&f);
	
	Flow &g =  mod->createFlow<FlowExponencial>();
	g.setSource(&Q2);
	g.setDestiny(&Q5);
	m1->setFlows(&g);
	
	Flow &h =  mod->createFlow<FlowExponencial>();
	h.setSource(&Q3);
	h.setDestiny(&Q4);
	m1->setFlows(&h);

	Flow &i =  mod->createFlow<FlowExponencial>();
    i.setSource(&Q4);
	i.setDestiny(&Q1);
	m1->setFlows(&i);

	Flow &j =  mod->createFlow<FlowExponencial>();
	j.setSource(&Q1);
	j.setDestiny(&Q3);	
	m1->setFlows(&j);
	
	Flow &k =  mod->createFlow<FlowExponencial>();
	k.setSource(&Q2);
	k.setDestiny(&Q3);	
	m1->setFlows(&k);

		
	m1->execute(0, 100, 0);
	//cout << "\nvalor de q1:" << Q1.getValue();
	//cout << "\nvalor de q2:" << Q2->getValue();
	assert(abs(Q1.getValue()-31.8513) < 0.0001);
	assert(abs(Q2.getValue()-18.4003) < 0.0001);
	assert(abs(Q3.getValue()-77.1143) < 0.0001);
	assert(abs(Q4.getValue()-56.1728) < 0.0001);
	assert(abs(Q5.getValue()-16.4612) < 0.0001);
	
}

/*
void testCase4() {
	
	Model *vai = new ModelImpl("Modelo3");
	Model *vai2 = new ModelImpl("Modelo 2");

	Stock *Q7 = new StockImpl(100, "Q1");
	Stock *Q6 = new StockImpl(0, "Q2");
	Stock *Q3 = new StockImpl(100, "Q3");
	Stock *Q4 = new StockImpl(0, "Q4");
	Stock *Q5 = new StockImpl(0, "Q5");
	Stock *Q2 = new StockImpl(*Q6);
	Stock *Q1 = new StockImpl();
	Q1 = Q7;
	
	vai->setStocks(Q1);
	vai->setStocks(Q2);
	vai->setStocks(Q3);
	vai->setStocks(Q4);
	vai->setStocks(Q5);
	
	Flow *f = new FlowExponencial();
	f->setSource( Q1);
	f->setDestiny(Q2);
	vai->setFlows(f);
	
	f = new FlowExponencial();
	f->setSource( Q2);
	f->setDestiny(Q5);
	vai->setFlows(f);
	
	f = new FlowExponencial();
	f->setSource( Q3);
	f->setDestiny(Q4);
	vai->setFlows(f);

	f = new FlowExponencial();
    f->setSource( Q4);
	f->setDestiny(Q1);
	vai->setFlows(f);

	f = new FlowExponencial();
	f->setSource( Q1);
	f->setDestiny(Q3);	
	vai->setFlows(f);
	
	f = new FlowExponencial();
	f->setSource( Q2);
	f->setDestiny(Q3);	
	vai->setFlows(f);

	*vai2 = *vai;
	vai->setFlows(f);
	delete (ModelImpl*)vai;	

	vai2->execute(0, 100, 0);
	assert(abs(Q1->getValue()-31.8513) < 0.0001);
	assert(abs(Q2->getValue()-18.4003) < 0.0001);
	assert(abs(Q3->getValue()-77.1143) < 0.0001);
	assert(abs(Q4->getValue()-56.1728) < 0.0001);
	assert(abs(Q5->getValue()-16.4612) < 0.0001);
	

}
*/

/*

void unitTest(){
	Stock *Q1 = new StockImpl(100,"Q1");
	assert(abs(Q1->getValue()-100) < 0.0001);
	assert(Q1->getName() == "Q1");
	
	Q1->setValue(0.5);
	assert(abs(Q1->getValue()-0.5) < 0.0001);	
	
	Q1->setName("OPA");
	assert(Q1->getName()=="OPA");
	
	Stock *Q2 = new StockImpl(*Q1);
	assert(Q2->getName()=="OPA");
	
	Q2->setName("A");
	assert(Q1->getName() == "OPA");
	assert(Q2->getName() == "A");
	
	Stock *Q3 = new StockImpl();
	*Q3 = *Q2;
	assert(Q3->getName() == "A");
	
	Q2->setName("B");
	assert(Q3->getName() =="A");
	
	Flow *F1 =new FlowExponencial();
	F1->setSource( Q1);
	F1->setDestiny(Q2);
	F1->setName("F1");
	assert(F1->getName() == "F1");
	
	F1->setName("G1");
	assert(F1->getName() == "G1");
	
	Flow *F2 =new FlowLogistica();
	F2->setName("G2");
	F2->setSource(Q3);
	F2->setDestiny(Q1);
	*F2 = *F1;
	assert(F2->getName() == "G1");
	
	F2->setName("G3");
	assert(F2->getName()=="G3");
	assert(F1->getName()=="G1");
	
	Model *mod1 = new ModelImpl("Modelo2");
	assert(mod1->getName()=="Modelo2");
	
	mod1->setStocks(Q3);
	mod1->setFlows(F2);
	mod1->setFlows(F1);
	
	Model *mod2 = new ModelImpl("Modelo3");
	*mod2 = *mod1;
	Stock *aux = new StockImpl();
	Stock *aux2 = new StockImpl();
	
	aux = mod1->getStocks(0);
	aux2 = mod2->getStocks(0);
	assert(aux->getName() == aux2->getName());
	assert(aux != aux2); //TESTANDO A FORMA CANONICA DO STOCK DENTRO DE MODELO
	
	aux->setName("AB");
	assert(mod2->getName()=="Modelo2");
	
	mod1->setName("Modelo4");
	assert(mod1->getName()=="Modelo4");
	Model *mod3 = new ModelImpl(*mod1);
	assert(mod3->getName()=="Modelo4");
	mod1->setName("QUALQUER");
	
	
	Model *mod4 = new ModelImpl("Modelo4");
	mod4->setStocks(aux);
	Flow *F3 =new FlowExponencial();
	F3->setSource( Q1);
	F3->setDestiny(Q2);
	mod4->setFlows(F3);
	Model *mod5 = new ModelImpl("Modelo5");
	*mod5 = *mod4;
	Flow *a1 =dynamic_cast<FlowExponencial *> (mod4->getFlows(0));
	Flow *a2 =dynamic_cast<FlowExponencial *> (mod5->getFlows(0));					
	assert(a1 != a2); 
	Model *mod6 = new ModelImpl("Modelo6");
	mod6->setStocks(aux);
	Flow *F4 =new FlowLogistica();
	F4->setSource( Q1);
	 F4->setDestiny(Q2);
	mod6->setFlows(F4);
	Model *mod7 = new ModelImpl("Modelo7");
	*mod7 = *mod6;
	Flow *a3 =dynamic_cast<FlowLogistica *> (mod6->getFlows(0));
	Flow *a4 =dynamic_cast<FlowLogistica *> (mod7->getFlows(0));				
	assert(a3 != a4); //TESTANDO A FORMA CANONICA DO STOCK DENTRO DE MODELO
	
	/*Stock *s1 = new StockImpl(200,"XORALUIZ");
	Stock *s2 = new StockImpl();
	*s2 = *s1;
	delete (StockImpl*)s1;
	cout<<s2->getName();
	*/
	
//}