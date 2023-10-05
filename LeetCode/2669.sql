SELECT artist, COUNT(*) occurrences
FROM Spotify
GROUP BY artist
ORDER BY occurrences DESC, artist;