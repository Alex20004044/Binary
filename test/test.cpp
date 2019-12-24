
#include <tchar.h>
#include <Binary.h>
#include <gtest\gtest.h>

using namespace std;
using namespace binary;

TEST(TestBinary, BinaryCreation_1) {

	char* str = "0";
	Binary b = Binary(str);
	EXPECT_STREQ(b.GetBin().c_str(), "00");
}
TEST(TestBinary, BinaryCreation_2) {

	char* str = "00000";
	Binary b = Binary(str);
	EXPECT_STREQ(b.GetBin().c_str(), "00");
}
TEST(TestBinary, BinaryCreation_3) {

	char* str = "-00000";
	Binary b = Binary(str);
	EXPECT_STREQ(b.GetBin().c_str(), "00");
}
TEST(TestBinary, BinaryCreation_4) {

	char* str = "1";
	Binary b = Binary(str);
	EXPECT_STREQ(b.GetBin().c_str(), "00");
}
TEST(TestBinary, BinaryCreation_5) {

	char* str = "-1";
	Binary b = Binary(str);
	EXPECT_STREQ(b.GetBin().c_str(), "11");
}
TEST(TestBinary, BinaryCreation_6) {

	char* str = "01";
	Binary b = Binary(str);
	EXPECT_STREQ(b.GetBin().c_str(), "01");
}
TEST(TestBinary, BinaryCreation_7) {

	char* str = "-01";
	Binary b = Binary(str);
	EXPECT_STREQ(b.GetBin().c_str(), "11");
}
TEST(TestBinary, BinaryCreation_8) {

	char* str = "2";
	Binary b = Binary(str);
	EXPECT_STREQ(b.GetBin().c_str(), "00");
}
TEST(TestBinary, BinaryCreation_9) {

	char* str = "-2";
	Binary b = Binary(str);
	EXPECT_STREQ(b.GetBin().c_str(), "00");
}
TEST(TestBinary, BinaryCreation_10) {

	char* str = "sadacva";
	Binary b = Binary(str);
	EXPECT_STREQ(b.GetBin().c_str(), "00");
}
TEST(TestBinary, BinaryCreation_11) {

	char* str = "-Mephie";
	Binary b = Binary(str);
	EXPECT_STREQ(b.GetBin().c_str(), "00");
}
TEST(TestBinary, BinaryCreation_12) {

	char* str = "+01";
	Binary b = Binary(str);
	EXPECT_STREQ(b.GetBin().c_str(), "01");
}
TEST(TestBinary, BinaryCreation_13) {

	char* str = "+1sa01";
	Binary b = Binary(str);
	EXPECT_STREQ(b.GetBin().c_str(), "00");
}

TEST(TestBinary, BinaryCreationNum_1) {

	int num = 1;
	Binary b = Binary(num);
	EXPECT_STREQ(b.GetBin().c_str(), "01");
}
TEST(TestBinary, BinaryCreationNum_2) {

	int num = 10;
	Binary b = Binary(num);
	EXPECT_STREQ(b.GetBin().c_str(), "01010");
}
TEST(TestBinary, BinaryCreationNum_3) {

	int num = -1;
	Binary b = Binary(num);
	EXPECT_STREQ(b.GetBin().c_str(), "11");
}
TEST(TestBinary, BinaryCreationNum_4) {

	int num = -10;
	Binary b = Binary(num);
	EXPECT_STREQ(b.GetBin().c_str(), "11010");
}
TEST(TestBinary, BinaryCreationNum_5) {

	int num = 11;
	Binary b = Binary(num);
	EXPECT_STREQ(b.GetBin().c_str(), "01011");
}
TEST(TestBinary, BinaryCreationNum_6) {

	int num = 0;
	Binary b = Binary(num);
	EXPECT_STREQ(b.GetBin().c_str(), "00");
}
TEST(TestBinary, BinaryInversal_1) {

	char* str = "01";
	Binary b = Binary(str);
	EXPECT_STREQ(b.GetInversalCode().c_str(), "01");
}
TEST(TestBinary, BinaryInversal_2) {

	char* str = "1";
	Binary b = Binary(str);
	EXPECT_STREQ(b.GetInversalCode().c_str(), "00");
}
TEST(TestBinary, BinaryInversal_3) {

	char* str = "10";
	Binary b = Binary(str);
	EXPECT_STREQ(b.GetInversalCode().c_str(), "00");
}
TEST(TestBinary, BinaryInversal_4) {

	char* str = "+0";
	Binary b = Binary(str);
	EXPECT_STREQ(b.GetInversalCode().c_str(), "00");
}
TEST(TestBinary, BinaryInversal_5) {

	char* str = "1111111";
	Binary b = Binary(str);
	EXPECT_STREQ(b.GetInversalCode().c_str(), "1000000");
}
TEST(TestBinary, BinaryInversal_6) {

	char* str = "0000";
	Binary b = Binary(str);
	EXPECT_STREQ(b.GetInversalCode().c_str(), "00");
}
TEST(TestBinary, BinaryAdditional_1) {

	char* str = "0000";
	Binary b = Binary(str);
	EXPECT_STREQ(b.GetAdditionalCode().c_str(), "00");
}
TEST(TestBinary, BinaryAdditional_2) {

	char* str = "1000";
	Binary b = Binary(str);
	EXPECT_STREQ(b.GetAdditionalCode().c_str(), "00");
}
TEST(TestBinary, BinaryAdditional_3) {

	char* str = "01100";
	Binary b = Binary(str);
	EXPECT_STREQ(b.GetAdditionalCode().c_str(), "01100");
}
TEST(TestBinary, BinaryAdditional_4) {

	char* str = "11100";
	Binary b = Binary(str);
	EXPECT_STREQ(b.GetAdditionalCode().c_str(), "10100");
}
TEST(TestBinary, BinaryAdditional_5) {

	char* str = "11101";
	Binary b = Binary(str);
	EXPECT_STREQ(b.GetAdditionalCode().c_str(), "10011");
}
TEST(TestBinary, BinaryAdditional_6) {

	char* str = "11111";
	Binary b = Binary(str);
	EXPECT_STREQ(b.GetAdditionalCode().c_str(), "10001");
}
TEST(TestBinary, BinaryAdditional_7) {

	char* str = "10001";
	Binary b = Binary(str);
	EXPECT_STREQ(b.GetAdditionalCode().c_str(), "11");
}
TEST(TestBinary, BinaryAdditional_8) {

	char* str = "-10000";
	Binary b = Binary(str);
	EXPECT_STREQ(b.GetAdditionalCode().c_str(), "110000");
}
TEST(TestBinary, BinaryAdd_1) {

	char* str1 = "01";
	char* str2 = "001";
	Binary b1 = Binary(str1);
	Binary b2 = Binary(str2);
	EXPECT_STREQ(b1.Add(b2).GetBin().c_str(), "010");
}
TEST(TestBinary, BinaryAdd_2) {

	char* str1 = "11";
	char* str2 = "01";
	Binary b1 = Binary(str1);
	Binary b2 = Binary(str2);
	EXPECT_STREQ(b1.Add(b2).GetBin().c_str(), "00");
}
TEST(TestBinary, BinaryAdd_3) {

	char* str1 = "1111";
	char* str2 = "0111";
	Binary b1 = Binary(str1);
	Binary b2 = Binary(str2);
	EXPECT_STREQ(b1.Add(b2).GetBin().c_str(), "00");
}
TEST(TestBinary, BinaryAdd_4) {

	char* str1 = "0111";
	char* str2 = "0111";
	Binary b1 = Binary(str1);
	Binary b2 = Binary(str2);
	EXPECT_STREQ(b1.Add(b2).GetBin().c_str(), "01110");
}
TEST(TestBinary, BinaryAdd_5) {

	char* str1 = "0101";
	char* str2 = "0111";
	Binary b1 = Binary(str1);
	Binary b2 = Binary(str2);
	EXPECT_STREQ(b1.Add(b2).GetBin().c_str(), "01100");
}
TEST(TestBinary, BinaryAdd_6) {

	char* str1 = "1101";
	char* str2 = "1111";
	Binary b1 = Binary(str1);
	Binary b2 = Binary(str2);
	EXPECT_STREQ(b1.Add(b2).GetBin().c_str(), "11100");
}
TEST(TestBinary, BinaryAdd_7) {

	char* str1 = "1101";
	char* str2 = "0111";
	Binary b1 = Binary(str1);
	Binary b2 = Binary(str2);
	EXPECT_STREQ(b1.Add(b2).GetBin().c_str(), "010");
}
TEST(TestBinary, BinaryAdd_8) {

	char* str1 = "1101";
	char* str2 = "00";
	Binary b1 = Binary(str1);
	Binary b2 = Binary(str2);
	EXPECT_STREQ(b1.Add(b2).GetBin().c_str(), "1101");
}
TEST(TestBinary, BinaryAdd_9) {

	char* str1 = "00";
	char* str2 = "1101";
	Binary b1 = Binary(str1);
	Binary b2 = Binary(str2);
	EXPECT_STREQ(b1.Add(b2).GetBin().c_str(), "1101");
}
TEST(TestBinary, BinaryAdd_10) {

	char* str1 = "00";
	char* str2 = "1101111110";
	Binary b1 = Binary(str1);
	Binary b2 = Binary(str2);
	EXPECT_STREQ(b1.Add(b2).GetBin().c_str(), "1101111110");
}
TEST(TestBinary, BinaryAdd_11) {

	char* str1 = "01";
	char* str2 = "1101111110";
	Binary b1 = Binary(str1);
	Binary b2 = Binary(str2);
	EXPECT_STREQ(b1.Add(b2).GetBin().c_str(), "1101111101");
}
TEST(TestBinary, BinaryAdd_12) {

	char* str1 = "01";
	char* str2 = "0101111110";
	Binary b1 = Binary(str1);
	Binary b2 = Binary(str2);
	EXPECT_STREQ(b1.Add(b2).GetBin().c_str(), "0101111111");
}
TEST(TestBinary, BinaryAdd_13) {

	char* str1 = "0101111110";
	char* str2 = "01";
	Binary b1 = Binary(str1);
	Binary b2 = Binary(str2);
	EXPECT_STREQ(b1.Add(b2).GetBin().c_str(), "0101111111");
}
TEST(TestBinary, BinaryAdd_14) {

	char* str1 = "1101111110";
	char* str2 = "11";
	Binary b1 = Binary(str1);
	Binary b2 = Binary(str2);
	EXPECT_STREQ(b1.Add(b2).GetBin().c_str(), "1101111111");
}
TEST(TestBinary, BinaryPreInc_1) {

	char* str1 = "1101111110";
	Binary b1 = Binary(str1);
	EXPECT_STREQ(b1.GetPreInc().GetBin().c_str(), "1101111101");
}
TEST(TestBinary, BinaryPreInc_2) {

	char* str1 = "0101111110";
	Binary b1 = Binary(str1);
	EXPECT_STREQ(b1.GetPreInc().GetBin().c_str(), "0101111111");
}
TEST(TestBinary, BinaryPreDec_1) {

	char* str1 = "1101111110";
	Binary b1 = Binary(str1);
	EXPECT_STREQ(b1.GetPreDec().GetBin().c_str(), "1101111111");
}
TEST(TestBinary, BinaryPreDec_2) {

	char* str1 = "0101111110";
	Binary b1 = Binary(str1);
	EXPECT_STREQ(b1.GetPreDec().GetBin().c_str(), "0101111101");
}
TEST(TestBinary, BinaryPostInc_1) {

	char* str1 = "0101111110";
	Binary b1 = Binary(str1);
	EXPECT_STREQ(b1.GetPostInc().GetBin().c_str(), "0101111110");
	EXPECT_STREQ(b1.GetBin().c_str(), "0101111111");
}
TEST(TestBinary, BinaryPostInc_2) {

	char* str1 = "0101111111";
	Binary b1 = Binary(str1);
	EXPECT_STREQ(b1.GetPostInc().GetBin().c_str(), "0101111111");
	EXPECT_STREQ(b1.GetBin().c_str(), "0110000000");
}
TEST(TestBinary, BinaryPostInc_3) {

	char* str1 = "00";
	Binary b1 = Binary(str1);
	EXPECT_STREQ(b1.GetPostInc().GetBin().c_str(), "00");
	EXPECT_STREQ(b1.GetBin().c_str(), "01");
}
TEST(TestBinary, BinaryPostInc_4) {

	char* str1 = "11";
	Binary b1 = Binary(str1);
	EXPECT_STREQ(b1.GetPostInc().GetBin().c_str(), "11");
	EXPECT_STREQ(b1.GetBin().c_str(), "00");
}
TEST(TestBinary, BinaryPostInc_5) {

	char* str1 = "110101";
	Binary b1 = Binary(str1);
	EXPECT_STREQ(b1.GetPostInc().GetBin().c_str(), "110101");
	EXPECT_STREQ(b1.GetBin().c_str(), "110100");
}
TEST(TestBinary, BinaryPostDec_1) {

	char* str1 = "0101111110";
	Binary b1 = Binary(str1);
	EXPECT_STREQ(b1.GetPostDec().GetBin().c_str(), "0101111110");
	EXPECT_STREQ(b1.GetBin().c_str(), "0101111101");
}
TEST(TestBinary, BinaryPostDec_2) {

	char* str1 = "0101111111";
	Binary b1 = Binary(str1);
	EXPECT_STREQ(b1.GetPostDec().GetBin().c_str(), "0101111111");
	EXPECT_STREQ(b1.GetBin().c_str(), "0101111110");
}
TEST(TestBinary, BinaryPostDec_3) {

	char* str1 = "00";
	Binary b1 = Binary(str1);
	EXPECT_STREQ(b1.GetPostDec().GetBin().c_str(), "00");
	EXPECT_STREQ(b1.GetBin().c_str(), "11");
}
TEST(TestBinary, BinaryPostDec_4) {

	char* str1 = "11";
	Binary b1 = Binary(str1);
	EXPECT_STREQ(b1.GetPostDec().GetBin().c_str(), "11");
	EXPECT_STREQ(b1.GetBin().c_str(), "110");
}
TEST(TestBinary, BinaryPostDec_5) {

	char* str1 = "110101";
	Binary b1 = Binary(str1);
	EXPECT_STREQ(b1.GetPostDec().GetBin().c_str(), "110101");
	EXPECT_STREQ(b1.GetBin().c_str(), "110110");
}
TEST(TestBinary, BinaryOperatorAdd_1) {

	char* str1 = "01";
	char* str2 = "001";
	Binary b1 = Binary(str1);
	Binary b2 = Binary(str2);
	Binary sum = (b1 + b2);
	EXPECT_STREQ(sum.GetBin().c_str(), "010");
}
TEST(TestBinary, BinaryOperatorAdd_2) {

	char* str1 = "11";
	char* str2 = "01";
	Binary b1 = Binary(str1);
	Binary b2 = Binary(str2);
	Binary sum = (b1 + b2);
	EXPECT_STREQ(sum.GetBin().c_str(), "00");
}
TEST(TestBinary, BinaryOperatorAdd_3) {

	char* str1 = "1111";
	char* str2 = "0111";
	Binary b1 = Binary(str1);
	Binary b2 = Binary(str2);
	Binary sum = (b1 + b2);
	EXPECT_STREQ(sum.GetBin().c_str(), "00");
}
TEST(TestBinary, BinaryOperatorAdd_4) {

	char* str1 = "0111";
	char* str2 = "0111";
	Binary b1 = Binary(str1);
	Binary b2 = Binary(str2);
	Binary sum = (b1 + b2);
	EXPECT_STREQ(sum.GetBin().c_str(), "01110");
}
TEST(TestBinary, BinaryOperatorAdd_5) {

	char* str1 = "0101";
	char* str2 = "0111";
	Binary b1 = Binary(str1);
	Binary b2 = Binary(str2);
	Binary sum = (b1 + b2);
	EXPECT_STREQ(sum.GetBin().c_str(), "01100");
}
TEST(TestBinary, BinaryOperatorAdd_6) {

	char* str1 = "1101";
	char* str2 = "1111";
	Binary b1 = Binary(str1);
	Binary b2 = Binary(str2);
	Binary sum = (b1 + b2);
	EXPECT_STREQ(sum.GetBin().c_str(), "11100");
}
TEST(TestBinary, BinaryOperatorAdd_7) {

	char* str1 = "1101";
	char* str2 = "0111";
	Binary b1 = Binary(str1);
	Binary b2 = Binary(str2);
	Binary sum = (b1 + b2);
	EXPECT_STREQ(sum.GetBin().c_str(), "010");
}
TEST(TestBinary, BinaryOperatorAdd_8) {

	char* str1 = "1101";
	char* str2 = "00";
	Binary b1 = Binary(str1);
	Binary b2 = Binary(str2);
	Binary sum = (b1 + b2);
	EXPECT_STREQ(sum.GetBin().c_str(), "1101");
}
TEST(TestBinary, BinaryOperatorAdd_9) {

	char* str1 = "00";
	char* str2 = "1101";
	Binary b1 = Binary(str1);
	Binary b2 = Binary(str2);
	Binary sum = (b1 + b2);
	EXPECT_STREQ(sum.GetBin().c_str(), "1101");
}

TEST(TestBinary, BinaryOperatorAdd_10) {

	char* str1 = "00";
	char* str2 = "1101111110";
	Binary b1 = Binary(str1);
	Binary b2 = Binary(str2);
	Binary sum = (b1 + b2);
	EXPECT_STREQ(sum.GetBin().c_str(), "1101111110");
}
TEST(TestBinary, BinaryOperatorAdd_11) {

	char* str1 = "01";
	char* str2 = "1101111110";
	Binary b1 = Binary(str1);
	Binary b2 = Binary(str2);
	Binary sum = (b1 + b2);
	EXPECT_STREQ(sum.GetBin().c_str(), "1101111101");
}
TEST(TestBinary, BinaryOperatorAdd__12) {

	char* str1 = "01";
	char* str2 = "0101111110";
	Binary b1 = Binary(str1);
	Binary b2 = Binary(str2);
	Binary sum = (b1 + b2);
	EXPECT_STREQ(sum.GetBin().c_str(), "0101111111");
}
TEST(TestBinary, BinaryOperatorAdd__13) {

	char* str1 = "0101111110";
	char* str2 = "01";
	Binary b1 = Binary(str1);
	Binary b2 = Binary(str2);
	Binary sum = (b1 + b2);
	EXPECT_STREQ(sum.GetBin().c_str(), "0101111111");
}
TEST(TestBinary, BinaryOperatorAdd__14) {

	char* str1 = "1101111110";
	char* str2 = "11";
	Binary b1 = Binary(str1);
	Binary b2 = Binary(str2);
	Binary sum = (b1 + b2);
	EXPECT_STREQ(sum.GetBin().c_str(), "1101111111");
}
TEST(TestBinary, BinaryOperatorSub_1) {

	char* str1 = "010";
	char* str2 = "001";
	Binary b1 = Binary(str1);
	Binary b2 = Binary(str2);
	EXPECT_STREQ((b1-b2).GetBin().c_str(), "01");
}

	TEST(TestBinary, BinaryOperatorPreInc_1) {

		char* str1 = "1101111110";
		Binary b1 = Binary(str1);
		Binary b2 = ++b1;
		EXPECT_STREQ(b2.GetBin().c_str(), "1101111101");
		EXPECT_STREQ(b1.GetBin().c_str(), "1101111101");
	}
	TEST(TestBinary, BinaryOperatorPreInc_2) {

		char* str1 = "0101111110";
		Binary b1 = Binary(str1);
		Binary b2 = ++b1;
		EXPECT_STREQ((b2).GetBin().c_str(), "0101111111");
		EXPECT_STREQ((b1).GetBin().c_str(), "0101111111");
	}
	TEST(TestBinary, BinaryOperatorPreInc_3) {

		char* str1 = "0101111110";
		Binary b1 = Binary(str1);
		Binary b2 = ++(++b1);
		EXPECT_STREQ((b2).GetBin().c_str(), "0110000000");
		EXPECT_STREQ((b1).GetBin().c_str(), "0110000000");
	}
	TEST(TestBinary, BinaryOperatorPostDec_1) {

		char* str1 = "0101111110";
		Binary b1 = Binary(str1);
		EXPECT_STREQ((b1--).GetBin().c_str(), "0101111110");
		EXPECT_STREQ(b1.GetBin().c_str(), "0101111101");
	}
	TEST(TestBinary, BinaryOperatorPostDec_2) {

		char* str1 = "0101111111";
		Binary b1 = Binary(str1);
		EXPECT_STREQ((b1--).GetBin().c_str(), "0101111111");
		EXPECT_STREQ(b1.GetBin().c_str(), "0101111110");
	}
	TEST(TestBinary, BinaryOperatorPostDec_3) {

		char* str1 = "00";
		Binary b1 = Binary(str1);
		EXPECT_STREQ((b1--).GetBin().c_str(), "00");
		EXPECT_STREQ(b1.GetBin().c_str(), "11");
	}
	TEST(TestBinary, BinaryOperatorPostDec_4) {

		char* str1 = "00";
		Binary b1 = Binary(str1);
		EXPECT_STREQ((--(b1--)).GetBin().c_str(), "11");
		EXPECT_STREQ(b1.GetBin().c_str(), "11");
	}
	TEST(TestBinary, BinaryOperatorEqual_1) {
		Binary b1 = Binary("000");
		Binary b2 = Binary("00");

		EXPECT_TRUE(b1 == b2);
	}
	TEST(TestBinary, BinaryOperatorNotEqual_1) {
		Binary b1 = Binary("0100");
		Binary b2 = Binary("00");

		EXPECT_TRUE(b1 != b2);
	}
	TEST(TestBinary, BinaryOperatorMinus_1) {
		Binary b1 = Binary("01");

		EXPECT_STREQ((-b1).GetBin().c_str(), "11");
	}
/*
TEST(TestBinary, BinaryCreationNum_7) {

long num = 10000000000000000000;
Binary b = Binary(num);
EXPECT_STREQ(b.GetBin(), "10000000000000000000");
}Z*/

int _tmain(int argc, _TCHAR* argv[])
{
	::testing::InitGoogleTest(&argc, argv);
	int t = RUN_ALL_TESTS();

	system("pause");
	return t;
}