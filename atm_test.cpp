#include "gtest/gtest.h"
#include "gmock/gmock.h" 
#include "atm.cpp"

class MockBankAPI : public BankAPI {
public:
  MOCK_METHOD(bool, verifyPIN, (const std::string& accountNumber, const std::string& pin), (override));
};

TEST(ATMControllerTest, deposit_withdraw) {
  MockBankAPI mockBankAPI;
  ATMController atm(mockBankAPI);
  EXPECT_CALL(mockBankAPI, verifyPIN("1234567890", "1234"))
      .WillOnce(testing::Return(true));

  atm.insertCard();
  atm.enterPIN("1234567890", "1234");
  ASSERT_EQ(atm.seeBalance("1234567890"), 0);
  atm.deposit("1234567890", 1000);
  atm.withdraw("1234567890", 500);
  ASSERT_EQ(atm.seeBalance("1234567890"), 500);
}

TEST(ATMControllerTest, withdraw_only) {
  MockBankAPI mockBankAPI;
  ATMController atm(mockBankAPI);
  EXPECT_CALL(mockBankAPI, verifyPIN("1234567890", "1234"))
      .WillOnce(testing::Return(true));

  atm.insertCard();
  atm.enterPIN("1234567890", "1234");
  atm.withdraw("1234567890", 500);
  ASSERT_EQ(atm.seeBalance("1234567890"), 0);
}

