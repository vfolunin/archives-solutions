SELECT
    sample_id,
    dna_sequence,
    species,
    dna_sequence REGEXP "^ATG" has_start,
    dna_sequence REGEXP "T(AA|AG|GA)$" has_stop,
    dna_sequence REGEXP "ATAT" has_atat,
    dna_sequence REGEXP "GGG" has_ggg
FROM samples
ORDER BY sample_id;