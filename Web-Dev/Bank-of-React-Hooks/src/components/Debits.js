import { Link } from 'react-router-dom';
import { useState } from 'react';
import AccountBalance from './AccountBalance';

const Debits = ({ accountBalance, debits, addDebit }) => {
  const [description, setDescription] = useState('');
  const [amount, setAmount] = useState('');
  const handleDescriptionChange = (e) => setDescription(e.target.value);
  const handleAmountChange = (e) => setAmount(e.target.value);

  const handleSubmit = (e) => {
    e.preventDefault();
    const newDebit = {
      id: Math.random().toString(36).substr(2, 9), // Generating a unique ID for each debit
      description,
      amount: parseFloat(amount),
      date: new Date().toISOString()
    };
    addDebit(newDebit);
    setDescription('');
    setAmount('');
  };

  const debitsView = () => {
    return debits.map((debit) => {
      const date = debit.date.slice(0, 10);
      return (
        <li key={debit.id}>
          {debit.amount} {debit.description} {date}
        </li>
      );
    });
  };

  return (
    <div>
      <h1>Debits</h1>

      <ul>
        {debitsView()}
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
        <button type="submit">Add Debit</button>
      </form>

      <AccountBalance accountBalance={accountBalance} />

      <br />
      <Link to="/">Return to Home</Link>
    </div>
  );
};

export default Debits;
