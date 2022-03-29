
#include <iostream>

// ����â�� ����ϱ� ���� �������.
#include <assert.h>

int StringLength(const char* Src)
{
    int   Length = 0;

    // 0 : false 0�� �ƴ� ��� �� : true
    while (Src[Length])
    {
        ++Length;
    }

    return Length;
}

void Test(const char Text[])
{
    char Text1[12] = {};
    std::cout << sizeof(Text) << std::endl;
    std::cout << sizeof(Text1) << std::endl;
}

bool StringCopy(char* Dest, const char* Src)
{
    int   Length = StringLength(Src);

    // Length + 1 ����Ʈ��ŭ �����ϴ� ������ ������
    // �ι��ڱ��� �����ϱ� ���ؼ��̴�.
    memcpy(Dest, Src, Length + 1);

    /*for (int i = 0; i < Length; ++i)
    {
       Dest[i] = Src[i];
    }

    Dest[Length] = 0;*/

    return true;
}

bool StringCopy(char* Dest, int Size, const char* Src)
{
    int   Length = StringLength(Src);

    if (Size < Length + 1)
    {
        assert(false);
        return false;
    }

    // Length + 1 ����Ʈ��ŭ �����ϴ� ������ ������
    // �ι��ڱ��� �����ϱ� ���ؼ��̴�.
    memcpy(Dest, Src, Length + 1);

    /*for (int i = 0; i < Length; ++i)
    {
       Dest[i] = Src[i];
    }

    Dest[Length] = 0;*/

    return true;
}

bool StringCat(char* Dest, int DestSize, const char* Src)
{
    int   DestLength = StringLength(Dest);
    int   SrcLength = StringLength(Src);

    // Dest �迭�� ��ü ũ�⿡�� ���ڿ��� �߰��� ũ�⸦ ����
    // �迭���� ���� ������ �����ش�.
    int AddSize = DestSize - DestLength;

    // �迭�� ���� ������ �־�� �� �������� ���� ���
    // ������ �߻���Ų��.
    if (AddSize <= SrcLength)
    {
        assert(false);
        return false;
    }

    memcpy(Dest + DestLength, Src, SrcLength + 1);

    /*for (int i = 0; i <= SrcLength; ++i)
    {
       Dest[i + DestLength] = Src[i];
    }*/

    return true;
}

bool StringCmp(const char* Dest, const char* Src)
{
    int   DestLength = StringLength(Dest);
    int SrcLength = StringLength(Src);

    // �� ���ڿ��� ���̰� �ٸ��ٸ� ������ �ٸ� ���ڿ��̴�.
    if (DestLength != SrcLength)
        return false;

    for (int i = 0; i < DestLength; ++i)
    {
        // �� ���ڿ��� �ϳ��� �ٸ��ٸ� �ٸ� ���ڿ��̴�.
        if (Dest[i] != Src[i])
            return false;
    }

    return true;
}

int main()
{
    std::cout << StringLength("Test") << std::endl;
    std::cout << StringLength("���ڿ� ����") << std::endl;

    Test("���� �׽�Ʈ");

    char   Text[64] = {};

    StringCopy(Text, "���ڿ� ����ǳ�?");

    std::cout << Text << std::endl;

    StringCopy(Text, 15, "10����Ʈ �̻�?");

    std::cout << Text << std::endl;

    StringCat(Text, 64, " �پ��!!");

    std::cout << Text << std::endl;

    if (StringCmp("������?", "������?"))
        std::cout << "�� ���ڴ� ����." << std::endl;

    return 0;
}