SELECT title, rating FROM movies
INNER JOIN ratings ON ratings.movie_id = movies.id
WHERE rating > 0 AND year = 2010 ORDER BY rating DESC, title ASC;