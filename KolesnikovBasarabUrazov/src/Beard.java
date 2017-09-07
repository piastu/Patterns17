package ru.nnesterov.smiley;

class Beard {
    private String name;
    private String age;
    private int photoId;

    Beard(String name, String age,int photoId) {
        this.name = name;
        this.age = age;
        this.photoId = photoId;
    }

    public String getName() {
        return name;
    }

    public int getPhotoId() {
        return photoId;
    }

    public String getAge() {

        return age;
    }
}