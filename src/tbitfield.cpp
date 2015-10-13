// ННГУ, ВМК, Курс "Методы программирования-2", С++, ООП
//
// tbitfield.cpp - Copyright (c) Гергель В.П. 07.05.2001
//   Переработано для Microsoft Visual Studio 2008 Сысоевым А.В. (19.04.2015)
//
// Битовое поле

#include "tbitfield.h"

TBitField::TBitField(int len)
{ 
	len=BitLen;
	MemLen=(len/(sizeof(TELEM)*8+1));
	pMem=new TELEM[MemLen];
	for(int i=0; i<MemLen; i++)
	pMem[i]=0;
}

TBitField::TBitField(const TBitField &bf) // конструктор копирования
{
}

TBitField::~TBitField()
{
}

int TBitField::GetMemIndex(const int n)  // индекс Мем для бита n
{return (n/sizeof(TELEM));}

TELEM TBitField::GetMemMask(int n)  // битовая маска для бита n
{n=n%(sizeof(TELEM)*8);   
		TELEM mask=1;
		 mask<<n;
		 return mask;
}

// доступ к битам битового поля

void TBitField::SetBit(const int n) // установить бит
{ 
	int m=GetMemIndex(n); 
	TELEM mask=GetMemMask(n);
	pMem[m]=pMem[m]|mask;
}


void TBitField::ClrBit(int n) // очистить бит
{

}

int TBitField::GetBit(const int n)  // получить значение бита
{
	int tmp=GetMemIndex(n);

}

// битовые операции

TBitField& TBitField::operator=(const TBitField &bf) // присваивание
{
}

int TBitField::operator==(const TBitField &bf) const // сравнение
{
  return 0;
}

int TBitField::operator!=(const TBitField &bf) const // сравнение
{
  return 0;
}

TBitField TBitField::operator|(const TBitField &bf) // операция "или"
{
	TBitField tmp(BitLen);
	for(int i=0; i<MemLen; i++)
		tmp.pMem[i]=pMem[i]|bf.GetMemMask[i];
	return tmp;
}

TBitField TBitField::operator&(const TBitField &bf) // операция "и"
{
}

TBitField TBitField::operator~(void) // отрицание
{
	TBitField tmp(BitLen);
	for(int i=0;i<MemLen;i++)
		tmp.pMem[i]=~pMem[i];
	return tmp;

}

// ввод/вывод

istream &operator>>(istream &istr, TBitField &bf) // ввод
{
}

ostream &operator<<(ostream &ostr, const TBitField &bf) // вывод
{
	for(int i=0;i<bf.BitLen; i++)
	{
		if (GetBit(i)) ostr<<1 ; 
		else ostr<<0;
	}
	return ostr;
}
