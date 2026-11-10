SELECT u1.user_name u1_name, u2.user_name u2_name
FROM
    followers f1
    JOIN followers f2 ON f1.user_id_fk = f2.following_user_id_fk AND f1.following_user_id_fk = f2.user_id_fk
    JOIN users u1 ON u1.user_id = f1.user_id_fk
    JOIN users u2 ON u2.user_id = f1.following_user_id_fk
WHERE u1.posts < u2.posts OR (u1.posts = u2.posts AND u1.user_id < u2.user_id)
ORDER BY u1.user_id;