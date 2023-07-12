//inserting inorder to perform operations
db.inventory.insertMany([
    { item: "journal", qty: 25, tags: ["blank", "red"], size: { h: 14, w: 21, uom: "cm" } },
    { item: "mat", qty: 85, tags: ["gray"], size: { h: 27.9, w: 35.5, uom: "cm" } },
    { item: "mousepad", qty: 25, tags: ["gel", "blue"], size: { h: 19, w: 22.85, uom: "cm" } }
 ])

 
//gives first document using limit
db.inventory.find().limit(1)

//skips the first document
db.inventory.find().skip(1)

db.inventory.find().skip(2) //skips first two document

//sorts the document i  ascending order use (+1)
db.inventory.find().sort({qty:1})

//sorts the documents in descending order use (-1)

db.inventory.find().sort({qty:-1})