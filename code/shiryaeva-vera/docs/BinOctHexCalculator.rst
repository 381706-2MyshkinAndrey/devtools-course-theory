������� ����: HEX,BIN,OCT �����������
=====================================

����� ``BinOctHexCalculator`` ������������ ��� ������������� ������� �������������� �������� � �������, ��������������� � ��������� �������� ���������.
� ��� ������������ ������:
  * ��������
  * ���������
  * ���������
  * �������
��� ������������� ����� � ��������� �������� ��������� ������������ ��������� ``Number``, ��������� �� ���������� ��������, ��������������� ������� ��������, � �������� ������� ���������, ��������������� ���������� �������������� ����.

.. code-block:: cpp

	enum Notation {Bin, Oct, Hex};

	struct Number
	{
		char* value;
		Notation notation; 
	};

	class BinOctHexCalculator
	{
	private:
		double NumberToDouble(Number a);
		Number DoubleToNumber(double a, Notation notation);
	public:
		BinOctHexCalculator(void);
		virtual ~BinOctHexCalculator(void);
		Number Add(Number a, Number b, Notation outputNotation);
		Number Sub(Number a, Number b, Notation outputNotation);
		Number Mult(Number a, Number b, Notation outputNotation);
		Number Div(Number a, Number b, Notation outputNotation);
	};

������ ������������� ������ � ���������������� C++ ����:

.. code-block:: cpp

	BinOctHexCalculator calc;
	Number a, b;
	a.Notation = Bin;
	a.value = "1001";
	b.Notation = Hex;
	b.value = "A03B";
	Number output = calc.Add(a,b);
