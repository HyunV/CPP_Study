
#include <iostream>

// 에러창을 출력하기 위한 헤더파일.
#include <assert.h>

int StringLength(const char* Src)
{
    int   Length = 0;

    // 0 : false 0이 아닌 모든 수 : true
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

    // Length + 1 바이트만큼 복사하는 이유는 마지막
    // 널문자까지 복사하기 위해서이다.
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

    // Length + 1 바이트만큼 복사하는 이유는 마지막
    // 널문자까지 복사하기 위해서이다.
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

    // Dest 배열의 전체 크기에서 문자열이 추가된 크기를 빼서
    // 배열에서 남은 공간을 구해준다.
    int AddSize = DestSize - DestLength;

    // 배열의 남은 공간이 넣어야 할 공간보다 작을 경우
    // 에러를 발생시킨다.
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

    // 두 문자열의 길이가 다르다면 무조건 다른 문자열이다.
    if (DestLength != SrcLength)
        return false;

    for (int i = 0; i < DestLength; ++i)
    {
        // 두 문자열중 하나라도 다르다면 다른 문자열이다.
        if (Dest[i] != Src[i])
            return false;
    }

    return true;
}

int main()
{
    std::cout << StringLength("Test") << std::endl;
    std::cout << StringLength("문자열 길이") << std::endl;

    Test("문자 테스트");

    char   Text[64] = {};

    StringCopy(Text, "문자열 복사되나?");

    std::cout << Text << std::endl;

    StringCopy(Text, 15, "10바이트 이상?");

    std::cout << Text << std::endl;

    StringCat(Text, 64, " 붙어라!!");

    std::cout << Text << std::endl;

    if (StringCmp("같을까?", "같을까?"))
        std::cout << "두 문자는 같다." << std::endl;

    return 0;
}