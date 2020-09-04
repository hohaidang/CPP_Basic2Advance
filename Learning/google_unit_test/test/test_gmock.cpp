#include <iostream>
#include <vector>
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <string>

/*gMock duoc dung khi gia lap 1 interface noi voi ben ngoai
  vd ta muon test functions cua class MyDataBase, trong MyDataBase se co 1 ham de
  goi den connect voi data base nam trong class DataBaseConnect nhung interface nay
  lai giao tiep voi ben ngoai, ta khong muon test interface nay
  Nen ta se force virtual function cho nhung interface noi voi ben ngoai nay
  roi sau do mock (gia lap) gia tri tra ve cho nhung interface nay de unit test
  cho component MyDataBase
  reference: https://www.youtube.com/watch?v=dLB2aDasVTg
  */

using namespace std;
using ::testing::AtLeast;
using ::testing::Return;
using ::testing::_;

class DataBaseConnect {
public:
	virtual bool login(string username, string password) {	return true; }
	virtual bool logout(string username) { return true; }
	virtual int fetchRecord() { return -1; }
};

class MockDB : public DataBaseConnect {
public:
	MOCK_METHOD0(fetchRecord, int());
	MOCK_METHOD1(logout, bool (string username));
	MOCK_METHOD2(login, bool (string username, string password));
};

class MyDataBase {
	DataBaseConnect & dbc; //TODO: remove reference later
public:
	MyDataBase(DataBaseConnect & _dbc) : dbc(_dbc) {}
	
	int Init(string username, string password) {
		if(dbc.login(username, password) != true) {
			cout << "DB FAILURE" << endl; return -1;
		} else {
			cout << "DB SUCCESS" << endl; return 1;
		}

	}
};

TEST(MyDBTest, LoginTest) {
	MockDB mdb;
	MyDataBase db(mdb);
	// override ham virtual login cua DataBaseConnect
	// expect ham nay duoc goi 1 lan va arguments cua ham login phai la "Terminator", "I'm Back"
	// va force gia tri tra ve la true
	EXPECT_CALL(mdb, login("Terminator", "I'm Back"))
	.Times(1)
	.WillOnce(Return(true));
	
	// boi vi gia tri tra ve cua ham login da bi force ve true, cho nen retValue = 1
	int retValue = db.Init("Terminator", "I'm Back");
	EXPECT_EQ(retValue, 1);	
}

TEST(MyDBTest, LoginFailure) {
	MockDB mdb;
	MyDataBase db(mdb);
	// expect any arguments
	EXPECT_CALL(mdb, login(_, _))
	.Times(1)
	.WillOnce(Return(false));
	
	int retValue = db.Init("Dang", "123");
	EXPECT_EQ(retValue, -1);
}

int main(int argc, char **argv) {
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
