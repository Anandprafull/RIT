CREATE TABLE SUPPLIER (
    Sid VARCHAR(10) PRIMARY KEY,
    Sname VARCHAR(100),
    Address VARCHAR(200)
);

CREATE TABLE PART (
    PID INT PRIMARY KEY,
    Pname VARCHAR(100),
    Color VARCHAR(50)
);

CREATE TABLE SHIPMENT (
    Sid VARCHAR(10),
    PID INT,
    Cost DECIMAL(10, 2),
    PRIMARY KEY (Sid, PID),
    FOREIGN KEY (Sid) REFERENCES SUPPLIER(Sid),
    FOREIGN KEY (PID) REFERENCES PART(PID)
);

INSERT INTO SUPPLIER (Sid, Sname, Address)
VALUES
('S1', 'Alice Supplies', 'Bangalore'),
('S2', 'Bob Traders', 'Mumbai'),
('S3', 'Charlie Wholesalers', 'Delhi'),
('S4', 'Diana Exports', 'Chennai'),
('S5', 'Eve Imports', 'Kolkata');

INSERT INTO PART (PID, Pname, Color)
VALUES
(1, 'Bolt', 'Green'),
(2, 'Nut', 'Red'),
(3, 'Washer', 'Blue'),
(4, 'Screw', 'Yellow'),
(5, 'Pin', 'Green');

INSERT INTO SHIPMENT (Sid, PID, Cost)
VALUES
('S1', 1, 50),
('S2', 2, 30),
('S3', 3, 40),
('S4', 4, 60),
('S5', 5, 70);

SELECT DISTINCT Sid
FROM SHIPMENT
JOIN PART ON SHIPMENT.PID = PART.PID
WHERE PART.Color = 'Green';

SELECT Sname, COUNT(PID) AS total_parts
FROM SUPPLIER
JOIN SHIPMENT ON SUPPLIER.Sid = SHIPMENT.Sid
GROUP BY Sname;

UPDATE PART
SET Color = 'Yellow'
WHERE PID IN (
    SELECT PID
    FROM SHIPMENT
    WHERE Sid = 'S3'
);

