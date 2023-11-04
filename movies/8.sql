SELECT name FROM people
JOIN stars ON  stars.person_id = people.id
JOIN movies ON movies.id = movie_id
WHERE movies.title = "Toy Story";