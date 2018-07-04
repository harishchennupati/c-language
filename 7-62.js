// in this we are extending classes
class animal{


constructor(name,height,weight)
{ this.name=name
  this.height=height
  this.weight=weight
  console.log("created animal named ",this.name)

}
namelength()
{
    return name.length
}
}
// in certain animals there are differences between fish and dog etc
//for ex dogs can bark and fishes cant bark
//fishes have swim speed
//we are inheriting class dog from animal
class Dog extends Animal{

 constructor(name,height,weight,barkVolume,leashColor,speed){
      //now we need to call a super constructor
 super(name,height,weight)//super constructor must
//be in constructor body

 this.barkVolume=barkVolume
 this.leashColor=leashColor
 this.spped=speed

 // at this point dog has 
 //height name weight barkvolume and leashcolor
 }
 bark(){
     if(this.barkVolume>50)
     { console.log(this.name ,"barks loudly volume",this.barkVolume)

     }
     else{
         console.log(this.name,"Borkls timidly volume",this.barkVolume)
     }
 }

}

var king=new Dog("King",45,92,72,"red",52)
king.bark()
//if we remove constructor of base class in derived
//class then wont work so we need to call super constructor
class fish extends Animal{

    constructor(name,height,weight,swimspeed)
    {
        super(name,height,weight)
        {
            this.swimspeed=swimspeed
        }
    }
    swim(chaserheight)
    {
        if(this.swimspeed>50)
        {
            console.log(this.name,"swims around clickly speed",this.swimspeed)

        }
        else
        console.log(this.name,"swims around slowly speed",this.swimspeed)
    }
    if(this.swimspeed>chaserheight)
    {
       console.log(this.name,"got away")
    }
    else{
        console.log(this.name,"was caught")
    }
}
var goldie=new fish("goldie",2,1,4)

goldie.swim(king.speed)
// we can continue extending classes and create want we 
//want like breeds of classes