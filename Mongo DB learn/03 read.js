// command to see all the data.. fetch all the data
 db.collection_name.find()

 // command to fetch selected data with condition

 db.collection_name.find({condition})

 //example: db.inventory.find({qty:90})

 db.inventory.find({tags:{$in:["cotton","copper"]}})

 //AND COMMAND
 db.inventory.find({status:"A",qty:{$lt:30}})

 //OR command
 db.inventory.find({$or:[{status:"A"},{qty:{$lt:30}}]})

 //retreiving only 1 document
 db.inventory.findOne({status:{$in:["A","D"]}})
