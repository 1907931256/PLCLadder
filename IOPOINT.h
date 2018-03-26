//File plc.h
#ifndef __PLC8_H
#define __PLC8_H
#define m_nAreRow 100
#define m_nAreCol 16

class CIO:public CObject
{
	DECLARE_SERIAL(CIO);
public:
	virtual void Serialize(CArchive &ar);	// �ĵ����л�
	CString name;
	CString addr;
	CString code;
	int Rows;
	int Cols;
	int flag;
	int fiveflag;
	int xpoint;
	int ypoint;
	CIO();
};

class IOPOINT:public CObject
{
	friend class LIST;
	friend class PLC;
protected:
	CString name;			// Ԫ������
	CString code;			// Ԫ�����ɵĴ���()
	CString addr;			// Ԫ����ַ(������)
	int  xpoint,ypoint;		// Ԫ��x��y����
	int  flag;				// �����������ӹ�ϵ
	int  fiveflag;			// ͼ���������ţ�ͼ����Ψһ���
	BOOL visit;				// 
	IOPOINT *right;			// ��������
	IOPOINT *down;			// ��������
	IOPOINT *left;			// ��������
	IOPOINT *up;			// ��������
	IOPOINT *unup;			// ѹջ����
	IOPOINT *undown;		// δ֪ͼ��
public:
	IOPOINT(int x,int y,int fl,CString cd="",CString nm="",CString ad="")
	{
		name=nm;
		code=cd;
		addr=ad;
		flag=fl;
		fiveflag=0;
		visit=FALSE;
		xpoint=x;
		ypoint=y;
		right=0;
		left=0;
		up=0;
		down=0;
		unup=0;
		undown=0;
	}
	IOPOINT()
	{
		name="";
		code="";
		addr="";
		flag=0;
		fiveflag=0;
		visit=FALSE;
		xpoint=0;
		ypoint=0;
		right=0;
		left=0;
		up=0;
		down=0;
		unup=0;
		undown=0;
	}
	void setname(const CString ioname)
	{
		name=ioname;
	}	
	void setaddr(const CString ioaddr)		// ���õ�ַ
	{
		addr=ioaddr;
	}
	void setcode(const CString iocode)		// �������ɵ�ָ��
	{
		code=iocode;
	}
	void setflag(int flg)
	{
		flag=flg;
	}
	void setfiveflag(int fivflg)
	{
		fiveflag=fivflg;
	}
	void setvisit(BOOL x)
	{
		visit=x;
	}
	void setwhere(int x,int y)
	{
		xpoint=x;
		ypoint=y;
	}
	void getname(CString *result_name)	// ��ȡԪ������
	{
		*result_name=name;
	}
	void getaddr(CString *result_addr)	// ��ȡ�޼���ַ
	{
		*result_addr=addr;
	}
	void getcode(CString *result_code)
	{
		*result_code=code;
	}
	int getflag()
	{
		return flag;
	}
	int getfiveflag()
	{
		return fiveflag;
	}
	int getxpoint()
	{
		return xpoint;
	}
	int getypoint()
	{
		return ypoint;
	}
	void changeimg(int,int,CDC *);
	virtual void setstatu() {}
	virtual void print(int x,int y,CDC *pDC)
	{
		changeimg(x,y,pDC);
	}
	virtual void put_img(int,int,CDC *){}
	virtual int testaddr();

};


class LD :public IOPOINT
{
public:
	LD(int x,int y,int flg,CString cd="LD",CString nm="",CString ad="")
		:IOPOINT(x,y,flg,cd,nm,ad)
	{};
	LD():IOPOINT()
	{
		setcode("LD");					
	}
	void put_img(int x,int y,CDC *pDC);
	void print(int x,int y,CDC *pDC);
};
class LDI :public IOPOINT
{
public:
	LDI(int x,int y,int flg,CString cd="LDI",CString nm="",CString ad="")
		:IOPOINT(x,y,flg,cd,nm,ad)
	{}
	LDI():IOPOINT()
	{
		setcode("LDI");
	}
	void put_img(int x,int y,CDC *pDC);
	void print(int x,int y,CDC *pDC);
};
class OR :public IOPOINT
{
public:
	OR(int x,int y,int flg,CString cd="OR",CString nm="",CString ad="")
		:IOPOINT(x,y,flg,cd,nm,ad)
	{}
	OR():IOPOINT()
	{
		setcode("OR");
	}
	void put_img(int x,int y,CDC *pDC);
	void print(int x,int y,CDC *pDC);
};
class ORI :public IOPOINT
{
public:
	ORI(int x,int y,int flg,CString cd="ORI",CString nm="",CString ad="")
		:IOPOINT(x,y,flg,cd,nm,ad)
	{}
	ORI():IOPOINT()
	{
		setcode("ORI");
	}
	void put_img(int x,int y,CDC *pDC);
	void print(int x,int y,CDC *pDC);
};
class HOR :public IOPOINT
{
public:
	HOR(int x,int y,int flg,CString cd="HOR",CString nm="",CString ad="")
		:IOPOINT(x,y,flg,cd,nm,ad)
	{}
	HOR():IOPOINT()
	{}
	int testaddr();
	void print(int x,int y,CDC *pDC);
};
class ERECT :public IOPOINT
{
public:
	ERECT(int x,int y,int flg,CString cd="ERECT",CString nm="",CString ad="")
		:IOPOINT(x,y,flg,cd,nm,ad)
	{}
	ERECT():IOPOINT()
	{}
	int testaddr()
	{
	 return 0;
	}
	void print(int x,int y,CDC *pDC);
};
class OUTPOINT :public IOPOINT
{
public:
	OUTPOINT(int x,int y,int flg,CString cd="OUT",CString nm="",CString ad="")
		:IOPOINT(x,y,flg,cd,nm,ad)
	{}
	OUTPOINT():IOPOINT()
	{
		setcode("OUT");
	}
	int testaddr()
	{
	 return 0;
	}
	void put_img(int x,int y,CDC  *pDC);
	void print(int x,int y,CDC *pDC);
};
class ADDTION:public IOPOINT
{
public:
	ADDTION(int x,int y,int flg,CString cd="",CString nm="",CString ad="")
		:IOPOINT(x,y,flg,cd,nm,ad)
	{}
	ADDTION():IOPOINT()
	{}
	int testaddr();
	void put_img(int x,int y,CDC *pDC);
	void print(int x,int y,CDC *pDC);
};

class LIST:public CObject
{
	friend class PLC;
private:
	IOPOINT *root;
public:
	LIST()
	{
	  root=0;
	}
	IOPOINT * ANBtest(IOPOINT *p);
	IOPOINT * ANBcompile(IOPOINT *p,IOPOINT *endpoint);
	IOPOINT * ORBtest(IOPOINT *p,IOPOINT *q);
	IOPOINT * ORBcompile(IOPOINT *p);
	int compile(IOPOINT *);
};
class PLC:public CObject
{
	friend class CLADDoc;
private:
	int Cols;
	int Rows;
	IOPOINT * point_array[m_nAreRow][m_nAreCol];
	LIST  list_array[20];
	int step;	
public:
	IOPOINT * getpoint(int row,int col);
	int getcols();
	int getrows();
	void SetRowCol(int row,int col);
	PLC();
	void getstep();
	int syntax(CString &m_strlist);
	int testpoint(int row,int col);
	void insert_point(IOPOINT *n);
	void remove_point(int x,int y);
	int compiled(CString &m_strlist);
	void newfile();
};

#endif





