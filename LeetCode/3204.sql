SELECT BIT_AND(permissions) common_perms, BIT_OR(permissions) any_perms
FROM user_permissions;