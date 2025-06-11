/*==================================================
The AccountBalance component displays account balance. It is included in other page views.
==================================================*/
import React from 'react';

const AccountBalance = ({ accountBalance }) => {
  return (
    <div>
      Balance: {accountBalance}
    </div>
  );
};

export default AccountBalance;
