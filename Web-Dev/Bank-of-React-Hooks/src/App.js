import React, { useState, useEffect } from 'react';
import { BrowserRouter as Router, Routes, Route } from 'react-router-dom';
import Home from './components/Home';
import UserProfile from './components/UserProfile';
import LogIn from './components/Login';
import Credits from './components/Credits';
import Debits from './components/Debits';

const App = () => {
  const [accountBalance, setAccountBalance] = useState(0);
  const [creditList, setCreditList] = useState([]);
  const [debitList, setDebitList] = useState([]);
  const [currentUser, setCurrentUser] = useState({
    userName: 'Joe Smith',
    memberSince: '11/22/99',
  });

  useEffect(() => {
    const fetchCredits = async () => {
      try {
        const response = await fetch('https://johnnylaicode.github.io/api/credits.json');
        if (!response.ok) {
          throw new Error(`Error! status: ${response.status}`);
        }
        const credits = await response.json();
        setCreditList(credits);
      } catch (err) {
        console.error(err);
      }
    };

    const fetchDebits = async () => {
      try {
        const response = await fetch('https://johnnylaicode.github.io/api/debits.json');
        if (!response.ok) {
          throw new Error(`Error! status: ${response.status}`);
        }
        const debits = await response.json();
        setDebitList(debits);
      } catch (err) {
        console.error(err);
      }
    };

    fetchCredits();
    fetchDebits();
  }, []);

  useEffect(() => {
    updateAccountBalance(creditList, debitList);
  }, [creditList, debitList]);

  const updateAccountBalance = (credits, debits) => {
    const totalCredits = credits.reduce((total, credit) => total + (typeof credit.amount === 'number' ? credit.amount : 0), 0);
    const totalDebits = debits.reduce((total, debit) => total + (typeof debit.amount === 'number' ? debit.amount : 0), 0);
    setAccountBalance(parseFloat((totalCredits - totalDebits).toFixed(2)));
  };

  const addCredit = (credit) => {
    const newCredits = [...creditList, credit];
    setCreditList(newCredits);
  };

  const addDebit = (debit) => {
    const newDebits = [...debitList, debit];
    setDebitList(newDebits);
  };

  const mockLogIn = (logInInfo) => {
    const newUser = { ...currentUser, userName: logInInfo.userName };
    setCurrentUser(newUser);
  };

  return (
    <Router basename="/bankofr">
      <div>
        <Routes>
          <Route path="/" element={<Home accountBalance={accountBalance} />} />
          <Route path="/userProfile" element={<UserProfile userName={currentUser.userName} memberSince={currentUser.memberSince} />} />
          <Route path="/login" element={<LogIn user={currentUser} mockLogIn={mockLogIn} />} />
          <Route path="/credits" element={<Credits accountBalance={accountBalance} credits={creditList} addCredit={addCredit} />} />
          <Route path="/debits" element={<Debits accountBalance={accountBalance} debits={debitList} addDebit={addDebit} />} />
        </Routes>
      </div>
    </Router>
  );
};

export default App;
