import React, { useState } from 'react';
import { Link } from 'react-router-dom';
import AccountBalance from './AccountBalance';

const Credits = ({ accountBalance, credits, addCredit }) => {
  const [description, setDescription] = useState('');
  const [amount, setAmount] = useState('');
  const handleDescriptionChange = (e) => setDescription(e.target.value);
  const handleAmountChange = (e) => setAmount(e.target.value);

  const handleSubmit = (e) => {
    e.preventDefault();
    const newCredit = {
      id: Math.random().toString(36).substr(2, 9),
      description,
      amount: parseFloat(amount),
      date: new Date().toISOString()
    };
    addCredit(newCredit);
    setDescription('');
    setAmount('');
  };

  return (
    <div>
      <h1>Credits</h1>
      <ul>
        {credits && credits.map((credit) => (
          <li key={credit.id}>
            {credit.amount} - {credit.description} on {new Date(credit.date).toLocaleDateString()}
          </li>
        ))}
      </ul>

      <form onSubmit={handleSubmit}>
        <div>
          <label>Description</label>
          <input type="text" name="description" value={description} onChange={handleDescriptionChange} />
        </div>
        <div>
          <label>Amount</label>
          <input type="number" name="amount" value={amount} onChange={handleAmountChange} />
        </div>
        <button type="submit">Add Credit</button>
      </form>

      <AccountBalance accountBalance={accountBalance} />

      <br />
      <Link to="/">Return to Home</Link>
    </div>
  );
};

export default Credits;
