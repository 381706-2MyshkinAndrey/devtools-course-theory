������ ��������: ��������� �����
================================
����� ``NumConverter`` ������������ ��� ������������� �����, ���������� � ��������� ����������� �������� ��������� (��������, ������������, ����������, �����������������). ����� ��������� ���������� ����� � ������ ������� ��������� �� ���������� ����.


.. code-block:: cpp

   enum NumSystem
    {
	hex,octal,decimal,binary
    };
    std::string dec_to_bin(int dec_number);
    class NumConverter
    {
    private:
	NumSystem NumSys;
	std::string Value;
    public:
	NumConverter(NumSystem myNumSys, std::string myValue);
	~NumConverter();
	std::string GetValue();
	int ToHex();
	int ToOctal();
	int ToDecimal();
	int ToBinary();
     };

������ �������������:
---------------------
.. code-block:: cpp

    NumConverter a(decimal,"100");
    a.ToBinary();
    std::cout<<a.GetValue()<<std::endl;