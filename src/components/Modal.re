[@react.component]
let make = (~closeModal: unit => unit, ~children) => {
  <>
    <div style=Styles.modalContainer>
      {children}
    </div>

    <div onClick={_ => closeModal()} style=Styles.modalOverlay></div>
  </>
};