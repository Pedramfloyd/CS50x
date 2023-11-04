---------------------------------

-- accessing to report details

SELECT * FROM crime_scene_reports
WHERE year = 2021 AND day = 28 AND month = 7 AND street = "Humphrey Street"
;

--OUTPUT
--(Theft of the CS50 duck took place at 10:15am at the Humphrey Street bakery.
--Interviews were conducted today with three witnesses who were present
--at the time – each of their interview transcripts mentions the bakery.)
--(Littering took place at 16:36. No known witnesses.)



-- checking interviews

SELECT transcript , name FROM interviews
WHERE year = 2021 AND day = 28 AND month = 7
;

--OUTPUT
--(-----------------------------------------------------------------------------------------------------------------------------------------------+---------+
--|                                                                                                                                                     transcript                                                                                                                                                      |  name   |
--+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+---------+
--| “Ah,” said he, “I forgot that I had not seen you for some weeks. It is a little souvenir from the King of Bohemia in return for my assistance in the case of the Irene Adler papers.”                                                                                                                               | Jose    |
--| “I suppose,” said Holmes, “that when Mr. Windibank came back from France he was very annoyed at your having gone to the ball.”                                                                                                                                                                                      | Eugene  |
--| “You had my note?” he asked with a deep harsh voice and a strongly marked German accent. “I told you that I would call.” He looked from one to the other of us, as if uncertain which to address.                                                                                                                   | Barbara |
--| Sometime within ten minutes of the theft, I saw the thief get into a car in the bakery parking lot and drive away. If you have security footage from the bakery parking lot, you might want to look for cars that left the parking lot in that time frame.                                                          | Ruth    |
--| I don't know the thief's name, but it was someone I recognized. Earlier this morning, before I arrived at Emma's bakery, I was walking by the ATM on Leggett Street and saw the thief there withdrawing some money.                                                                                                 | Eugene  |
--| As the thief was leaving the bakery, they called someone who talked to them for less than a minute. In the call, I heard the thief say that they were planning to take the earliest flight out of Fiftyville tomorrow. The thief then asked the person on the other end of the phone to purchase the flight ticket. | Raymond |
--| Our neighboring courthouse has a very annoying rooster that crows loudly at 6am every day. My sons Robert and Patrick took the rooster to a city far, far away, so it may never bother us again. My sons have successfully arrived in Paris.                                                                        | Lily    |
--+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+---------+)


--Search for name of the thief

SELECT name , receiver , amount ,  caller FROM people
JOIN passengers ON people.passport_number = passengers.passport_number
JOIN phone_calls ON phone_calls.caller = people.phone_number
JOIN bank_accounts ON bank_accounts.person_id = people.id
JOIN flights ON flights.id = passengers.flight_id
JOIN bakery_security_logs ON bakery_security_logs.license_plate = people.license_plate
JOIN atm_transactions ON atm_transactions.account_number = bank_accounts.account_number
WHERE
bakery_security_logs.year = 2021 AND
bakery_security_logs.month = 7 AND
bakery_security_logs.day = 28 AND
bakery_security_logs.hour = 10 AND
15 <= bakery_security_logs.minute <= 25 AND
bakery_security_logs.activity = 'exit' AND
atm_transactions.year = 2021 AND
atm_transactions.month = 7 AND
atm_transactions.day = 28 AND
atm_transactions.transaction_type = 'withdraw' AND
atm_transactions.atm_location = 'Leggett Street' AND
flights.year = 2021 AND
flights.month = 7 AND
flights.day = 29 AND
flights.minute = 20 AND
flights.hour = 8 AND
flights.origin_airport_id = 8 AND
phone_calls.duration < 60 AND
phone_calls.year = 2021 AND
phone_calls.month = 7 AND
phone_calls.day = 28
;

--OUTPUT
--+--------+----------------+--------+----------------+
--|  name  |    receiver    | amount |     caller     |
--+--------+----------------+--------+----------------+
--| Bruce  | (375) 555-8161 | 50     | (367) 555-5533 |
--| Taylor | (676) 555-6554 | 60     | (286) 555-6063 |
--+--------+----------------+--------+----------------+

--now we have two names as bruce and taylor


-- search for destination city

SELECT destination_airport_id , origin_airport_id , city , full_name , abbreviation FROM flights
JOIN airports ON airports.id = flights.destination_airport_id
WHERE
flights.year = 2021 AND
flights.month = 7 AND
flights.day = 29 AND
flights.minute = 20
;

--OUTPUT
--+------------------------+-------------------+---------------+-----------------------------+--------------+
--| destination_airport_id | origin_airport_id |     city      |          full_name          | abbreviation |
--+------------------------+-------------------+---------------+-----------------------------+--------------+
--| 4                      | 8                 | New York City | LaGuardia Airport           | LGA          |
--| 9                      | 8                 | Tokyo         | Tokyo International Airport | HND          |
--+------------------------+-------------------+---------------+-----------------------------+--------------+

-- new york is destination of bruce and tokyo for taylor


-- name of people whom was receiver on phone call ,


SELECT name, phone_calls.duration FROM people
JOIN phone_calls ON people.phone_number = phone_calls.receiver
WHERE
phone_calls.year = 2021 AND
phone_calls.month = 7 AND
phone_calls.day = 28 AND
phone_calls.duration <= 60
ORDER BY phone_calls.duration
;

--OUTPUT
--+------------+----------+
--|    name    | duration |
--+------------+----------+
--| Larry      | 36       |
--| Jacqueline | 38       |
--| James      | 43       |
--| Robin      | 45       |
--| Philip     | 49       |
--| Melissa    | 50       |
--| Jack       | 51       |
--| Anna       | 54       |
--| Doris      | 55       |
--| Luca       | 60       |
--+------------+----------+

-- taylor was speaking on call with james and bruce with robin



SELECT name, phone_calls.duration FROM people
JOIN phone_calls ON people.phone_number = phone_calls.caller
WHERE
phone_calls.year = 2021 AND
phone_calls.month = 7 AND
phone_calls.day = 28 AND
phone_calls.duration <= 60
ORDER BY phone_calls.duration
;

--OUTPUT
--+---------+----------+
--|  name   | duration |
--+---------+----------+
--| Kelsey  | 36       |
--| Carina  | 38       |
--| Taylor  | 43       |
--| Bruce   | 45       |
--| Diana   | 49       |
--| Kelsey  | 50       |
--| Sofia   | 51       |
--| Benista | 54       |
--| Kenny   | 55       |
--| Kathryn | 60       |
--+---------+----------+




-- finding the hour of flying and destination city from origin airport .


SELECT destination_airport_id  , city , full_name , minute , hour FROM flights
JOIN airports ON airports.id = flights.destination_airport_id
WHERE
flights.year = 2021 AND
flights.month = 7 AND
flights.day = 29 AND
flights.minute = 20 AND
flights.origin_airport_id = 8
;

--OUTPUT
--+------------------------+---------------+-----------------------------+--------+------+
--| destination_airport_id |     city      |          full_name          | minute | hour |
--+------------------------+---------------+-----------------------------+--------+------+
--| 4                      | New York City | LaGuardia Airport           | 20     | 8    |
--| 9                      | Tokyo         | Tokyo International Airport | 20     | 15   |
--+------------------------+---------------+-----------------------------+--------+------+

-- so bruce is thief because he has flight on 8:20
-- the first time of flying in day of 29 and the destination city in new york
-- so robin is the person that helped bruce //