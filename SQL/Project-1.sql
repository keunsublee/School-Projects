DROP DATABASE IF EXISTS project1;

CREATE DATABASE project1;

USE project1;

CREATE TABLE Player_account (
	profile_id INT PRIMARY KEY,
	username VARCHAR(50), 
	email VARCHAR(75),
	user_password VARCHAR(50),
    profile_info VARCHAR(255)
);

CREATE TABLE Game_character (
	char_id INT PRIMARY KEY,
	profile_id INT,
    char_name VARCHAR(50),
    char_class VARCHAR(50),
    level INT,
    EXP INT,
    HP INT,
    MP INT,
    money INT,
    skills VARCHAR(200),
    FOREIGN KEY (profile_id) REFERENCES Player_account(profile_id)
);

CREATE TABLE Items (
    item_id INT PRIMARY KEY,
    item_name VARCHAR(50),
    item_type VARCHAR(25),
    rarity VARCHAR(10),
    item_effect VARCHAR(200),
    item_cost INT
);

CREATE TABLE Inventory (
	inventory_id INT PRIMARY KEY,
	char_id INT,
    item_id INT,
    quantity INT,
	equip BOOL,
    FOREIGN KEY (char_id) REFERENCES Game_character(char_id)
);

CREATE TABLE Transactions (
    transaction_id INT PRIMARY KEY,
    buyer_id INT,
    seller_id INT,
    item_id INT,
    money INT,
    t_time datetime,
	CONSTRAINT fk_Items FOREIGN KEY (item_id) REFERENCES Items(item_id),
    CONSTRAINT fk_buyer FOREIGN KEY (buyer_id) REFERENCES Game_character(char_id),
	CONSTRAINT fk_seller FOREIGN KEY (seller_id) REFERENCES Game_character(char_id)
);

CREATE TABLE Quests (
    quest_id INT PRIMARY KEY,
    quest_name VARCHAR(100),
    min_level INT,
    objectives TINYTEXT,
    rewards TINYTEXT,
    rewards_id INT,
    CONSTRAINT fk_rewards_id FOREIGN KEY (rewards_id) REFERENCES Items(item_id)
);

CREATE TABLE Character_quests (
	char_quest_id INT PRIMARY KEY,
    quest_id INT,
    char_id INT,
    completion_status ENUM('In Progress', 'Completed', 'Failed'),
    progress_percentage INT,
	CONSTRAINT fk_quest_id FOREIGN KEY (quest_id) REFERENCES Quests(quest_id),
    FOREIGN KEY (char_id) REFERENCES Game_character(char_id)
);

CREATE TABLE Guilds (
	guild_id INT PRIMARY KEY,
    guild_name VARCHAR(50),
    created datetime
);

CREATE TABLE Guild_members (
	guild_id INT,
    char_id INT,
    member_role VARCHAR(50),
	CONSTRAINT fk_Guild_member FOREIGN KEY (char_id) REFERENCES Game_character(char_id),
    FOREIGN KEY (guild_id) REFERENCES Guilds(guild_id)
);

CREATE TABLE Parties (
	party_id INT PRIMARY KEY,
    party_type ENUM('PvP', 'PvE'),
    session_start datetime,
	session_end datetime
);

CREATE TABLE Party_members (
	party_id INT,
    char_id INT,
    session_join datetime,
	outcome ENUM('Win', 'Loss', 'Draw', 'Conquered', 'Failed', 'In Progress'),
    CONSTRAINT fk_Party_Character FOREIGN KEY (char_id) REFERENCES Game_character(char_id),
	FOREIGN KEY (party_id) REFERENCES Parties(party_id)
);

INSERT INTO Player_account (profile_id, username, email, user_password, profile_info) VALUES
(0100, 'testuser', 'a@a.com', 'pass', 'profile'),
(29843848, 'Whirlwind49', 'Jordon_Jenkins27@gmail.com', '2XGijpSj', 'I like dogs.'),
(88347576, 'radicalow1', 'watson50@gmail.com', 'Ng9TP9735f', 'Will party with anyone!.'),
(71869563, 'St333ve', 'Sammie318@gmail.com', 'A6ddBBO9d', 'Hi!'),
(0000, 'NPCs', 'None', '0S9IuSJs65', 'NA');

INSERT INTO Game_character (char_id, profile_id, char_name, char_class, level, EXP, HP, MP, money, skills) VALUES
(0100, '100', 'testchar', 'testclass', '1', '0', '0', '0', '0', '1'),
(5113054, '29843848', 'Erik', 'Paladin', '32', '81000', '4800', '96', '35850', 'Thunder Blade, Shield Bash'),
(4327555, '29843848', 'Simon', 'Black Mage', '45', '183000', '5850', '180', '67000', 'Mightly Flare, Blizzard, Amplify'),
(7328804, '88347576', 'Sancho', 'Warrior', '69', '2161000', '8970', '207', '149500', 'Berserk, Power Slash, Colossal Swing'),
(1409944, '88347576', 'Rakari', 'Ninja', '71', '2790000', '9130', '213', '198000', 'Accelerate, Fatal Stab, Invisible'),
(4100398, '71869563', 'Yan', 'Priest', '19', '19900', '2850', '66', '13000', 'Heal, Spark'),
(0000010, '0000', 'Shopkeeper1', 'NPC', '0', '0', '0', '0', '0', 'NA'),
(0000011, '0000', 'Pedestrian2', 'NPC', '0', '0', '0', '0', '0', 'NA');

INSERT INTO Items (item_id, item_name, item_type, rarity, item_effect, item_cost) VALUES
(200, 'testitem', 'testtype', 'K', 'itemeffect', '0'),
(694270, 'Medicinal Herb', 'Medicine', 'E', 'Recover 25% HP.', '1000'),
(538264, 'Strong Potion', 'Medicine', 'C', 'Recover 50% HP.', '2500'),
(497630, 'Mythical Herb', 'Medicine', 'A', 'Cure all status effects and recover 70% HP.', '20000'),
(421012, 'Divine Powder', 'Medicine', 'S', 'Cure all status effects and recover 100% HP.', '40000'),
(194209, 'Iron Ore', 'Material', 'C', 'Used to craft C rarity armor. Can be found on Island 1 and Island 3.', '8000'),
(064209, 'Abyss Stone', 'Material', 'B', 'Used to craft B rarity armor. Can be found on Island 1.', '14000'),
(032693, 'Flame Stone', 'Material', 'B', 'Used to craft B rarity weapons. Can be found on Island 2.', '15000'),
(978694, 'Chimera Soul', 'Material', 'A', 'Used to craft A rarity weapons. Can be found on Island 3.', '35000'),
(091672, 'Iron Axe', 'Weapon', 'D', 'Increases damage from attacks dealt by Warrior and Paladin by 6%.', '7000'),
(546378, 'Sorcerer Rod', 'Weapon', 'D', 'Increases damage from attacks dealt by Black Mage and Preist by 5%.', '7000'),
(103948, 'Elf Staff', 'Weapon', 'B', 'Increases damage from attacks dealt by Black Mage and Preist by 11%.', '21000'),
(239487, 'Venomous Kunai', 'Weapon', 'B', 'Increases damage from attacks dealt by Ninja by 12%. 30% chance to inflict Posion onto attacked enemy.', '22000'),
(781581, 'Inferno Blade', 'Weapon', 'B', 'Increases damage from attacks dealt by Warrior and Paladin by 14%', '20000'),
(723077, 'Galaxy Staff', 'Weapon', 'S', 'Reduce MP cost for skills used by Black Mage and Priest by 25%', '70000'),
(016699, 'Magic Armor', 'Armor', 'D', 'Reduce damage received by 4%. Increase MP by 6 points.', '4000'),
(110948, 'High-Grade Battle Armor', 'Armor', 'C', 'Reduce damage received by 7%. Increase HP by 200 points.', '9000'),
(266017, 'Ice Dragon Armor', 'Armor', 'A', 'Reduce damage received by 15%. Immune to Freeze.', '40000'),
(463092, 'Absolute Armor', 'Armor', 'S', 'Reduce damage received by 21%.', '80000'),
(121902, 'Map', 'Key Item', 'K', 'Used to view the world map.', '0'),
(436349, 'VIP Letter', 'Key Item', 'K', 'Important letter written by ..... .', '0');


INSERT INTO Inventory (inventory_id, char_id, item_id, quantity, equip) VALUES
(300, '100', '200', '1', FALSE),
(29771, '5113054', '538264', '9', FALSE),
(29772, '5113054', '781581', '1', TRUE),
(29773, '5113054', '110948', '1', TRUE),
(29774, '5113054', '121902', '1', FALSE),
(29775, '5113054', '091672', '1', FALSE),
(29776, '5113054', '194209', '3', FALSE),
(11621, '4327555', '103948', '1', TRUE),
(11622, '4327555', '110948', '1', TRUE),
(11623, '4327555', '091672', '1', FALSE),
(11624, '4327555', '538264', '6', FALSE),
(11625, '4327555', '194209', '5', FALSE),
(86691, '7328804', '538264', '26', FALSE),
(86692, '7328804', '497630', '5', FALSE),
(86693, '7328804', '781581', '1', TRUE),
(86694, '7328804', '463092', '1', TRUE),
(86695, '7328804', '091672', '1', FALSE),
(86696, '7328804', '032693', '3', FALSE),
(86697, '7328804', '121902', '1', FALSE),
(86698, '7328804', '436349', '1', FALSE),
(44701, '1409944', '538264', '19', FALSE),
(44702, '1409944', '497630', '8', FALSE),
(44703, '1409944', '421012', '1', FALSE),
(44704, '1409944', '463092', '1', TRUE),
(44705, '1409944', '239487', '1', TRUE),
(44706, '1409944', '121902', '1', FALSE),
(44707, '1409944', '436349', '1', FALSE),
(44708, '1409944', '032693', '4', FALSE),
(44709, '1409944', '064209', '5', FALSE),
(44710, '1409944', '723077', '1', FALSE),
(71841, '4100398', '694270', '5', FALSE),
(71842, '4100398', '546378', '1', TRUE),
(71843, '4100398', '016699', '1', TRUE),
(71844, '4100398', '194209', '3', FALSE),
(71845, '4100398', '121902', '1', FALSE);

INSERT INTO Transactions (transaction_id, buyer_id, seller_id, item_id, money, t_time) VALUES
(400, '100', '10', '200', '0', '2024-11-21 14:34:55'),
(36364894, '5113054', '0000010', '091672', '7000', '2024-11-21 14:34:55'),
(36266806, '4327555', '1409944', '538264', '7500', '2024-11-26 23:58:14'),
(36394665, '4327555', '1409944', '194209', '16000', '2024-11-27 00:02:29');


INSERT INTO Quests (quest_id, quest_name, min_level, objectives, rewards, rewards_id) VALUES
(500, 'testquest', '1', 'objectives', 'testreward', '200'),
(7694, 'Slime Hunting', '5', 'Kill 5 slimes on Island 1', 'testreward', '200'),
(0471, 'Emerald Dragon King', '60', 'Defeat the rampaging Emerald Dragon King', 'Mythical Herb', '497630'),
(1202, 'Quelling the Flames', '20', 'Defeat the leader of the Goblin tribe on Island 2', 'Medicinal Herb', '694270'),
(4212, 'To the Hidden Land', '35', 'Conquer the Hidden Land dungeon', 'Iron Axe', '091672'),
(6344, 'Brand New World', '10', 'Reach Island 2.', 'testreward', '200'),
(7110, 'The King Where It All Began', '70', 'Defeat the King of the Underworld.', 'Divine Powder', '421012');

INSERT INTO Character_quests (char_quest_id, quest_id, char_id, completion_status, progress_percentage) VALUES
(600, '500', '100', 'Completed', '100'),
(68946202, '7694', '5113054', 'Completed', '100'),
(68946203, '1202', '5113054', 'Completed', '100'),
(68946205, '6344', '5113054', 'Completed', '100'),
(67946201, '4212', '4327555', 'In Progress', '75'),
(67946202, '7694', '4327555', 'Completed', '100'),
(67946203, '6344', '4327555', 'Completed', '100'),
(67946204, '1202', '4327555', 'Failed', '50'),
(66946201, '1202', '7328804', 'Completed', '100'),
(66946202, '6344', '7328804', 'Completed', '100'),
(66946203, '0471', '7328804', 'In Progress', '75'),
(65946201, '1202', '1409944', 'Completed', '100'),
(65946202, '6344', '1409944', 'Completed', '100'),
(65946203, '0471', '1409944', 'Completed', '100'),
(65946204, '7110', '1409944', 'In Progress', '25'),
(64946201, '7694', '4100398', 'Completed', '100'),
(64946202, '6344', '4100398', 'In Progress', '50');

INSERT INTO Guilds (guild_id, guild_name, created) VALUES
(700, 'testguild', '2024-11-05 20:53:15'),
(1192356, 'Team Ragnarok', '2024-11-05 20:53:15');

INSERT INTO Guild_members (guild_id, char_id, member_role) VALUES
(700, '100', 'Leader'),
(700, '5113054', 'Member'),
(1192356, '1409944', 'Leader'),
(1192356, '4327555', 'Officer'),
(1192356, '4100398', 'Member');

INSERT INTO Parties (party_id, party_type, session_start, session_end) VALUES
(800, 'PVE', '2024-10-28 20:53:15', NULL),
(2953910, 'PvE', '2024-10-28 21:42:11', '2024-10-28 22:22:51'),
(2963924, 'PvP', '2024-10-29 19:02:31', '2024-10-29 19:22:03');

INSERT INTO Party_members (party_id, char_id, session_join, outcome) VALUES
(800, '100', '2024-10-28 20:53:15', 'In Progress'),
(2953910, '1409944', '2024-10-28 22:22:52', 'Conquered'),
(2953910, '4327555', '2024-10-28 22:44:01', 'Conquered'),
(2953910, '4100398', '2024-10-28 22:47:45', 'Conquered'),
(2963924, '1409944', '2024-10-29 19:22:13', 'Win'),
(2963924, '4327555', '2024-10-29 19:22:13', 'Loss');


-- SELECT * FROM Player_account;
-- SELECT * FROM Game_character;
-- SELECT * FROM Items;
-- SELECT * FROM Inventory;
-- SELECT * FROM Transactions ;
-- SELECT * FROM Quests;
-- SELECT * FROM Character_quests;
-- SELECT * FROM Guilds;
-- SELECT * FROM Guild_members;
-- SELECT * FROM Parties;
-- SELECT * FROM Party_members;

-- QUERY 1: Retrieve information about a player by their username.
SELECT username, profile_id, email, user_password, profile_info 
FROM Player_account
WHERE username = 'St333ve';

-- QUERY 2:  List all characters associated with a specific player.
SELECT profile_id, char_id, char_name 
FROM Game_character
WHERE profile_id = '88347576';

-- QUERY 3:  Find all items currently owned by a particular character
SELECT  inv.char_id, inv.item_id, it.item_name, inv.quantity
FROM Items it
JOIN Inventory inv on it.item_id = inv.item_id
WHERE inv.char_id = '1409944';

-- QUERY 4:  List all active quests for a specific character.
SELECT cq.char_id, cq.quest_id, q.quest_name, cq.completion_status, cq.progress_percentage
FROM Quests q
JOIN Character_quests cq on cq.quest_id = q.quest_id
WHERE cq.char_id = '4327555' AND cq.completion_status = 'In Progress';

-- Query 5:  Get the members of a particular guild.
SELECT gm.guild_id, gm.char_id, gm.member_role, g.guild_name, c.char_name
FROM Guild_members gm, Guilds g, Game_character c
WHERE gm.guild_id = '700' and g.guild_id = '700' and c.char_id = gm.char_id;

-- Query 6:Retrieve the details of a transaction between two characters.
SELECT t.transaction_id, t.buyer_id, t.seller_id, t.item_id, t.money, t.t_time
FROM Transactions t
WHERE t.buyer_id = '100' and t.seller_id = '10';

-- Query 7: Find all parties currently active for a specific type of activity (e.g., dungeon). --PVE
SELECT p.party_type, p.party_id, p.party_type, p.session_start, p.session_end
FROM Parties p
WHERE p.party_type = 'PvE' and p.session_end is NULL;


-- Query 8: List items of a specific rarity (e.g., legendary) across all players.
SELECT i.rarity, i.item_id, i.item_name, i.item_type, gc.char_id
FROM Items i
JOIN Inventory inv ON i.item_id = inv.item_id
JOIN Game_character gc ON inv.char_id = gc.char_id
WHERE i.rarity = 'S';

-- Query 9: Calculate the total experience points for a player across all of their characters.
SELECT pa.profile_id, SUM(gc.EXP) AS total_experience
FROM Player_account pa
JOIN Game_character gc ON pa.profile_id = gc.profile_id
GROUP BY pa.profile_id;

-- Query 10: Retrieve all completed quests for a character.
SELECT cq.char_id, cq.quest_id, q.quest_name, cq.completion_status
FROM Quests q
JOIN Character_quests cq ON cq.quest_id = q.quest_id
WHERE cq.char_id = '5113054' AND cq.completion_status = 'Completed';