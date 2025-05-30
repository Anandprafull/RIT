-- Drop existing tables if they exist
DROP TABLE IF EXISTS BATTING;
DROP TABLE IF EXISTS BOWLING;
DROP TABLE IF EXISTS MATCH;
DROP TABLE IF EXISTS PLAYER;

CREATE TABLE PERSON (
    driver_id VARCHAR(50) PRIMARY KEY,
    name VARCHAR(100),
    address VARCHAR(200)
);

CREATE TABLE CAR (
    Regno VARCHAR(20) PRIMARY KEY,
    model VARCHAR(50),
    year INT
);

CREATE TABLE ACCIDENT (
    report_number INT PRIMARY KEY,
    acc_date DATE,
    location VARCHAR(200)
);

CREATE TABLE OWNS (
    driver_id VARCHAR(50),
    Regno VARCHAR(20),
    PRIMARY KEY (driver_id, Regno),
    FOREIGN KEY (driver_id) REFERENCES PERSON(driver_id),
    FOREIGN KEY (Regno) REFERENCES CAR(Regno)
);

CREATE TABLE PARTICIPATED (
    driver_id VARCHAR(50),
    Regno VARCHAR(20),
    report_number INT,
    damageamount DECIMAL(10, 2),
    PRIMARY KEY (driver_id, Regno, report_number),
    FOREIGN KEY (driver_id) REFERENCES PERSON(driver_id),
    FOREIGN KEY (Regno) REFERENCES CAR(Regno),
    FOREIGN KEY (report_number) REFERENCES ACCIDENT(report_number)
);

INSERT INTO PERSON (driver_id, name, address)
VALUES
('D1', 'Alice', 'Bangalore'),
('D2', 'Bob', 'Mumbai'),
('D3', 'Charlie', 'Delhi'),
('D4', 'Diana', 'Chennai'),
('D5', 'Eve', 'Kolkata');

INSERT INTO CAR (Regno, model, year)
VALUES
('KA01AB1234', 'Toyota', 2020),
('MH02CD5678', 'Honda', 2018),
('DL03EF9101', 'Hyundai', 2019),
('TN04GH2345', 'Ford', 2021),
('WB05IJ6789', 'Kia', 2022);

INSERT INTO ACCIDENT (report_number, acc_date, location)
VALUES
(101, '2024-12-01', 'Bangalore'),
(102, '2024-12-02', 'Mumbai'),
(103, '2024-12-03', 'Delhi'),
(104, '2024-12-04', 'Chennai'),
(105, '2024-12-05', 'Kolkata');

INSERT INTO OWNS (driver_id, Regno)
VALUES
('D1', 'KA01AB1234'),
('D2', 'MH02CD5678'),
('D3', 'DL03EF9101'),
('D4', 'TN04GH2345'),
('D5', 'WB05IJ6789');

INSERT INTO PARTICIPATED (driver_id, Regno, report_number, damageamount)
VALUES
('D1', 'KA01AB1234', 101, 5000),
('D2', 'MH02CD5678', 102, 10000),
('D3', 'DL03EF9101', 103, 7000),
('D4', 'TN04GH2345', 104, 3000),
('D5', 'WB05IJ6789', 105, 8000);

SELECT DISTINCT Regno
FROM PARTICIPATED;

SELECT CAR.Regno, CAR.model
FROM PARTICIPATED
JOIN CAR ON PARTICIPATED.Regno = CAR.Regno
ORDER BY PARTICIPATED.damageamount DESC
LIMIT 1;

SELECT driver_id, COUNT(Regno) AS num_cars
FROM OWNS
GROUP BY driver_id;
