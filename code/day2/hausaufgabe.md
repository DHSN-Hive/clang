# Aufgabe 12.01.

Lesen einer Datei mit Struktur:

```
abc:abc:abc
bde:123:TTT
```

Inhalt bestehender Datei umwandeln in neue Datei mit TAB-separiert statt ':'. Ziel-Datei soll überschreiben werden, wenn vorhanden.

## Ziel:
`./mycopy` liefert

```
srcdatei    dstdatei
---         ---
part1       part2
```

## Hinweise

`FILE;[gets; puts; fgets]; fopen; fclose`
`sktok`
